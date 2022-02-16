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
    delete currentUser;
    delete tempUser;
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
template <typename K>
void AHttpService::GetJsonStringFromStruct(K FilledStruct, FString& StringOutput) {
    FJsonObjectConverter::UStructToJsonObjectString(K::StaticStruct(), &FilledStruct, StringOutput, 0, 0);
}
//This takes a Json string and fills the StructOutput with the struct created from the Json.
template <typename T>
void AHttpService::GetStructFromJsonString(FHttpResponsePtr Response, T& StructOutput) {
    T StructData;
    FString JsonString = Response->GetContentAsString();
    FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &StructOutput, 0, 0);
}


/**************************************************************************************************************************/

void AHttpService::GetPlayer(int ind)
{
    FString sample = "http://localhost:8800/api/User";
    sample.Append(FString::FromInt(ind));
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *sample);
    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    //Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::LoginResponse);
    //And finally actually Sending the request.
    Send(Request);
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *Request->GetVerb()); 
}

void AHttpService::callCheckLogin(FString email, FString password)
{
    Fdata* LoginCredentials = new Fdata();
    LoginCredentials->email = email;
    LoginCredentials->password = password;
    CheckLogin(LoginCredentials);
}

void AHttpService::CheckLogin(Fdata* LoginCredentials)
{
    this->tempUser = LoginCredentials;
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
            this->currentUser = &LoginResponse.data[x];
            this->correct = true;
            UE_LOG(LogTemp, Warning, TEXT("Login Successful!"));
            this->tempUser = nullptr;
            return;
        }
    }
    this->tempUser = nullptr;
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
    this->tempUser = nullptr;
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
}