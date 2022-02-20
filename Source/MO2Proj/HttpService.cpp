// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpService.h"
#include "DataList.h"
#include "MainUIWidget.h"

AHttpService::AHttpService()
{ 
    PrimaryActorTick.bCanEverTick = false; 
}

AHttpService::~AHttpService()
{
    this->currentUser = nullptr;
    this->tempUser = nullptr;
    this->signUpAccountData = nullptr;
    delete currentUser;
    delete tempUser;
    delete signUpAccountData;
}

void AHttpService::BeginPlay() { 
    Super::BeginPlay(); 
    Http = &FHttpModule::Get(); 
    
        // You can uncomment this out for testing.
    
    //callSearchPlayer("sonson");
    //CheckLogin(LoginCredentials);
    //GetPlayer(1);
    //Login(LoginCredentials);
}

TSharedRef<IHttpRequest> AHttpService::RequestWithRoute(FString route) {
    auto Request = Http->CreateRequest();
    Request->SetURL(route);
    SetRequestHeaders((TSharedRef<IHttpRequest>&)Request);
    return (TSharedRef<IHttpRequest>&)Request;
}

void AHttpService::SetRequestHeaders(TSharedRef<IHttpRequest>& Request) {
    Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));
}

//you would put "user/1" as the Subroute. This is for the Subroute
TSharedRef<IHttpRequest> AHttpService::GetRequest(FString route) {
    TSharedRef<IHttpRequest> Request = RequestWithRoute(route);
    Request->SetVerb("GET");
    return Request;
}

//you would put "user/1" as the Subroute and FString for the Json string / body.
TSharedRef<IHttpRequest> AHttpService::PostRequest(FString Subroute, FString ContentJsonString) {
    TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute);
    Request->SetVerb("POST");
    Request->SetContentAsString(ContentJsonString);
    return Request;
}

//This is really just some semantics for cleaner code as well.
void AHttpService::Send(TSharedRef<IHttpRequest>& Request) {
    Request->ProcessRequest();
}

/*
* bWasSuccessful | UE4's Http Response comes back with this parameter. It comes into play when a 
server flat out refuses the connection. For instance if the server crashed, or is down. It should 
always be the first thing checked.
Response.IsValid() | As far as I can tell this comes back false when the response code is 200 ( OK ) 
but the response itself is malformed in an unusable way.
EHttpResponseCodes::IsOk(Response->GetResponseCode()) | If this is not true then we UE_LOG out the 
response code that came back from the server ( 401, 404, 500, etc ) and return false.
*/
bool AHttpService::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
    if (!bWasSuccessful || !Response.IsValid()) 
        return false; 
    if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) 
        return true; 
    else 
    { UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode()); return false; } }

/*
* This can be used to set the Authorization header on a Request as needed since APIs are stateless
and have no recollection of who the user requesting information is. You can use this to authenticate
users for authenticated requests.
*/
void AHttpService::SetAuthorizationHash(FString Hash, TSharedRef<IHttpRequest>& Request) {
    Request->SetHeader(AuthorizationHeader, Hash);
}



/**************************************************************************************************************************/
//Serializers and Deserializers
//These are two ** methods to make life easy when going from struct to json or vice versa.

/*
* This takes a USTRUCT() Like the one we made before, FRequest_Login and turns it into a properly
formatted Json string. The variable passed into the StringOutput will be filled with the Json.
*/
void AHttpService::GetJsonStringFromStruct(Fdata FilledStruct, FString& StringOutput) {
    FJsonObjectConverter::UStructToJsonObjectString(Fdata::StaticStruct(), &FilledStruct, StringOutput, 0, 0);
}
//This takes a Json string and fills the StructOutput with the struct created from the Json.
template <typename T>
void AHttpService::GetStructFromJsonString(FHttpResponsePtr Response, T& StructOutput) {
    T StructData;
    FString JsonString = Response->GetContentAsString();
    FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &StructOutput, 0, 0);
}


/**************************************************************************************************************************/

void AHttpService::callCheckLogin(FString email, FString password)
{
    this->tempUser = new Fdata();
    this->tempUser->email = email;
    this->tempUser->password = password;
    CheckLogin();
}

void AHttpService::CheckLogin()
{
    FString sample = "http://localhost:8800/api/User/";
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *sample);
    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::CheckLoginResponse);
    //And finally actually Sending the request.
    Send(Request);
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *Request->GetVerb()); 
}

void AHttpService::CheckLoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FResponse_Login_Arr LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);

    for(int x = 0; x < LoginResponse.data.Num(); x++)
    {
        if((LoginResponse.data[x].email == this->tempUser->email || LoginResponse.data[x].username == this->tempUser->email)&&
            LoginResponse.data[x].password == this->tempUser->password)
        {
            //store the current login user
            this->currentUser = new Fdata();
            this->currentUser = &LoginResponse.data[x];
            this->currentUsername = this->currentUser->username;
            this->correct = true;
            this->myWidget->disableLoginButton();
            callSearchPlayer(this->currentUser->username);
            UE_LOG(LogTemp, Warning, TEXT("Login Successful!"));
            return;
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("Login Unsuccessful!: %s : %s"),*this->tempUser->email, *this->tempUser->password ); 
}

void AHttpService::callSearchPlayer(FString username)
{
	this->tempUser = new Fdata();
    this->tempUser->username = username;
    SearchPlayer(username);
}

void AHttpService::SearchPlayer(FString username)
{
    FString sample = "http://localhost:8800/api/UserPS/";
    sample.Append(username);

    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::GetPlayerResponse);
    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::GetPlayerResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FSearchPlayer_U LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    //UE_LOG some tests to make sure our code is working.

    if(this->FindComponentByClass<UDataList>() == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Error Finding Actor component!"));
    }
	UDataList* dataList = this->FindComponentByClass<UDataList>();
 
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Response->GetContentAsString());
    dataList->playerName = this->tempUser->username;
    dataList->goalsPerMatch = LoginResponse.data.goalsPerMatch;
    dataList->knockoutsPerMatch = LoginResponse.data.knockoutsPerMatch;
    dataList->mvpPercentage = LoginResponse.data.mvpPercentage;
    dataList->totalMatch = LoginResponse.data.totalMatch;
    dataList->winPercentage = LoginResponse.data.winPercentage;
 
    UE_LOG(LogTemp, Warning, TEXT("goalsPerMatch is: %d"), dataList->goalsPerMatch);
    UE_LOG(LogTemp, Warning, TEXT("knockoutsPerMatch is: %d"), dataList->knockoutsPerMatch);
    UE_LOG(LogTemp, Warning, TEXT("mvpPercentage is: %d"), dataList->mvpPercentage);
    UE_LOG(LogTemp, Warning, TEXT("totalMatch is: %d"), dataList->totalMatch);
    UE_LOG(LogTemp, Warning, TEXT("winPercentage is: %d"), dataList->winPercentage);
    
    this->myWidget->executePlayerSearch();
    this->myWidget->executePlayerSearchRowData(LoginResponse.rowData);
}

bool AHttpService::checkLoginSearchPlayer()
{
	if(this->currentUsername.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Empty!!!!!!!"));
        this->myWidget->cleanUpYourStatsWindow();
        return false;
	}
    else
    {
		callSearchPlayer(this->currentUsername);
		return true;
    }
    return false;
}

void AHttpService::onLogout()
{
    this->currentUsername = "\0";
    this->currentUser = nullptr;
	this->myWidget->cleanUpYourStatsWindow();
}

void AHttpService::CallCommunityResult()
{
    FString sample = "http://localhost:8800/api/UserCS/";

    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::GetCommunityResponse);
    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::GetCommunityResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FGetCommunity_U LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    //UE_LOG some tests to make sure our code is working.

    this->myWidget->executeCommunitySearchRowData(LoginResponse);
    this->myWidget->showCommunityData();
}

void AHttpService::CallMetaRankingResult()
{
    FString sample = "http://localhost:8800/api/UserMR/";

    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::GetMetaRankingResponse);
    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::GetMetaRankingResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FGetMetaRanking_U LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    //UE_LOG some tests to make sure our code is working.

    this->myWidget->executeMetaRankingRowData(LoginResponse);
    this->myWidget->showMetaRankingData();
}

void AHttpService::CallPokemonProfile(FString pokemonName)
{
    FString sample = "http://localhost:8800/api/UserPP/";
    sample.Append(pokemonName);
    
    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::GetPokemonProfileResponse);
    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::GetPokemonProfileResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FPokemonProfile_U LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    //UE_LOG some tests to make sure our code is working.
	UDataList* dataList = this->FindComponentByClass<UDataList>();

    if(LoginResponse.rowData.pokemonName.Equals("Charizard"))
    {
	    dataList->pickedPokemonName = 0;
    }
    else if(LoginResponse.rowData.pokemonName.Equals("Cinderace"))
    {
	    dataList->pickedPokemonName = 1;
    }
    else if(LoginResponse.rowData.pokemonName.Equals("Venusaur"))
    {
	    dataList->pickedPokemonName = 2;
    }
    else if(LoginResponse.rowData.pokemonName.Equals("Pikachu"))
    {
	    dataList->pickedPokemonName = 3;
    }
    else if(LoginResponse.rowData.pokemonName.Equals("Blastoise"))
    {
	    dataList->pickedPokemonName = 4;
    }

    this->myWidget->executePokemonProfileRowData(LoginResponse);
    this->myWidget->showPokemonProfileData();
}

void AHttpService::CallSignUpAccount()
{
    FString sample = "http://localhost:8800/api/User";
    
    //get the jsonstring
    FString ContentJsonString;
    GetJsonStringFromStruct(this->signUpAccountData->data, ContentJsonString);
    
    TSharedRef<IHttpRequest> Request = PostRequest(sample, ContentJsonString);
   
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::SignUpResponse);
    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::SignUpResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;
    
    FResponse_Login LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    
    UE_LOG(LogTemp, Warning, TEXT("Username is: %s"), *LoginResponse.data.username);
    UE_LOG(LogTemp, Warning, TEXT("Email is: %s"), *LoginResponse.data.email);
    UE_LOG(LogTemp, Warning, TEXT("Password is: %s"), *LoginResponse.data.password);
    UE_LOG(LogTemp, Warning, TEXT("Account Created Success!!"));

    //this->myWidget->showSignUpResponse();
}


void AHttpService::CheckSignUpFields()
{
    FString sample = "http://localhost:8800/api/User/";
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *sample);
    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::CheckSignUpFieldsResponse);
    //And finally actually Sending the request.
    Send(Request);
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *Request->GetVerb()); 
}

void AHttpService::CheckSignUpFieldsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FResponse_Login_Arr LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);
    
    UE_LOG(LogTemp, Warning, TEXT("Username is: %s"), *this->signUpAccountData->data.username);
    UE_LOG(LogTemp, Warning, TEXT("Email is: %s"), *this->signUpAccountData->data.email);
    UE_LOG(LogTemp, Warning, TEXT("Password is: %s"), *this->signUpAccountData->data.password);

	//check if there are similar email, similar username
    for(int x = 0; x < LoginResponse.data.Num(); x++)
    {
        if((LoginResponse.data[x].email == this->signUpAccountData->data.email ||
            LoginResponse.data[x].username == this->signUpAccountData->data.username))
        {
            UE_LOG(LogTemp, Warning, TEXT("Email / Username is already taken!"));
            return;
        }
    }

    //if the input data is valid, then call this request
    this->CallSignUpAccount();
}