//============================================================================
// Name        : Test_Arduino_Json_MinGW.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ArduinoJson.h"
#include <stdio.h>

using namespace std;

char messageInputArray[100] = "{\"name\":\"test\",\"number\":3}";
const char* message = "{\"name\":\"test\",\"number\":3  }";

void deserialise(char* testJson, const char* message){

	DynamicJsonDocument doc(304);
	deserializeJson(doc, testJson);
	const char* name = doc["name"];
	printf("%s", message);
	printf("The value of name is, %s.\r\n", name);

}

void deserialiseConst(const char* testJson, const char* message){

	DynamicJsonDocument doc(304);
	deserializeJson(doc, testJson);
	const char* name = doc["name"];
	printf("%s", message);
	printf("The value of name is, %s.\r\n", name);

}

void dynamicSizeDocumentTest(char* testJson, int size){

	DynamicJsonDocument doc(size);
	deserializeJson(doc, testJson);
	const char* name = doc["name"];
	printf("The dynamically sized value of name is, %s.\r\n", name);

}

int main() {

	deserialise(messageInputArray, "This will work fine,");

	// functions passes char* so document attempts to write
	// to the existing memory location of the mes sage input
	// array
	deserialise(messageInputArray, "This will fail so the value should be null,");

	memcpy(messageInputArray, message, strlen(message));
	dynamicSizeDocumentTest(messageInputArray, 304);
	// printf("The value of the number is %i.", number);

	memcpy(messageInputArray, message, strlen(message));
	deserialise(messageInputArray, "This will work as the memory has been reallocated.");

	memcpy(messageInputArray, message, strlen(message));
	deserialiseConst(messageInputArray, "This will work.");

	// Arduino Json won't write to read only memory
	deserialiseConst(messageInputArray, "This will work as this function takes a const char*.");
	deserialiseConst(message, "This will also work as this function takes a const char*.");

	return 0;
}
