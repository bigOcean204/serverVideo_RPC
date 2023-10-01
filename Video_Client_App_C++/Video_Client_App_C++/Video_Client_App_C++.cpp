// File Example1Client.cpp
#include <iostream>
#include "client_server_interface.h"

int main()
{
    RPC_STATUS status;
    unsigned char* szStringBinding = NULL;
    // Call to RpcStringBindingCompose - same as before.
    handle_t hClientBindings = NULL;
    // Creates a string binding handle.
    // This function is nothing more than a printf.
    // Connection is not done here.
    status = RpcStringBindingCompose(
        NULL,                                        // UUID to bind to.
        (RPC_CSTR)("ncacn_ip_tcp"),// Use TCP/IP protocol.
        (RPC_CSTR)("localhost"),   // TCP/IP network address to use.
        (RPC_CSTR)("4747"),        // TCP/IP port to use.
        NULL,                                    // Protocol dependent network options to use.
        &szStringBinding);                       // String binding output.

    if (status)
        exit(status);

    // Validates the format of the string binding handle and converts
    // it to a binding handle.
    // Connection is not done here either.
    status = RpcBindingFromStringBinding(
        szStringBinding,        // The string binding to validate.
        &hClientBindings);     // Put the result in the explicit binding
    // handle defined in the IDL file.

    if (status)
        exit(status);

    RpcTryExcept
    {
        // Calls the RPC function. The hExample1Binding binding handle
        // is used implicitly.
        // Connection is done here.
        unsigned char success = 0;
        unsigned char pFileUpdate[] = "MyUploadFile";

        Upload(hClientBindings, pFileUpdate, &success);
        RequestTrim(hClientBindings,20,30,&success);
        RequestMerge(hClientBindings, pFileUpdate, pFileUpdate, &success);
        Download(hClientBindings, &success);

    }
        RpcExcept(1)
    {
        std::cerr << "Runtime reported exception " << RpcExceptionCode()
            << std::endl;
    }
    RpcEndExcept

        // Free the memory allocated by a string.
        status = RpcStringFree(
            &szStringBinding); // String to be freed.

    if (status)
        exit(status);

    // Releases binding handle resources and disconnects from the server.
    status = RpcBindingFree(
        &hClientBindings); // Frees the implicit binding handle defined in the IDL file.

    if (status)
        exit(status);
}

// Memory allocation function for RPC.
// The runtime uses these two functions for allocating/deallocating
// enough memory to pass the string to the server.
void* __RPC_USER midl_user_allocate(size_t size)
{
    return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
    free(p);
}