// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpService.h"

AHttpService::AHttpService()
{ 
    PrimaryActorTick.bCanEverTick = false; 
}

void AHttpService::BeginPlay() { 
    Super::BeginPlay(); 
    Http = &FHttpModule::Get(); 
    
        // You can uncomment this out for testing.
    FRequest_Login LoginCredentials;
    LoginCredentials.email = TEXT("asdf@asdf.com");
    LoginCredentials.password = TEXT("asdfasdf");
    GetPlayer(1);
    //Login(LoginCredentials);
}

TSharedRef<IHttpRequest> AHttpService::RequestWithRoute(FString Subroute) {
    auto Request = Http->CreateRequest();
    Request->SetURL(ApiBaseUrl + Subroute);
    SetRequestHeaders((TSharedRef<IHttpRequest>&)Request);
    return (TSharedRef<IHttpRequest>&)Request;
}

void AHttpService::SetRequestHeaders(TSharedRef<IHttpRequest>& Request) {
    Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));
}

//you would put "user/1" as the Subroute. This is for the Subroute
TSharedRef<IHttpRequest> AHttpService::GetRequest(FString Subroute) {
    TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute);
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
    FString sample = "User/";
    sample.Append(FString::FromInt(ind));
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *sample);
    TSharedRef<IHttpRequest> Request = GetRequest(sample);
    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::LoginResponse);
    //And finally actually Sending the request.
    Send(Request);
    
    UE_LOG(LogTemp, Warning, TEXT("RequestType is: %s"), *Request->GetVerb()); 
}

void AHttpService::Login(FRequest_Login LoginCredentials) {
    //Creating a Json string from a struct
    FString ContentJsonString;
    //jsonbody
    GetJsonStringFromStruct(LoginCredentials, ContentJsonString);

    //Getting a Post Request Object with the route "user/login"
    TSharedRef<IHttpRequest> Request = PostRequest("user/login", ContentJsonString);

    //Setting the method to be executed when the response returns ( or times out / fails )
    Request->OnProcessRequestComplete().BindUObject(this, &AHttpService::LoginResponse);

    //And finally actually Sending the request.
    Send(Request);
}

void AHttpService::LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    //Make sure the response is valid before continuing.
    if (!ResponseIsValid(Response, bWasSuccessful)) return;

    //Get a struct from the Json string
    FResponse_Login LoginResponse;
    GetStructFromJsonString(Response, LoginResponse);

    //UE_LOG some tests to make sure our code is working.
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Response->GetContentAsString());
    UE_LOG(LogTemp, Warning, TEXT("Id is: %d"), LoginResponse.responseData.id);
    UE_LOG(LogTemp, Warning, TEXT("Name is: %s"), *LoginResponse.responseData.name);
    UE_LOG(LogTemp, Warning, TEXT("Score is: %d"), LoginResponse.responseData.score);
}