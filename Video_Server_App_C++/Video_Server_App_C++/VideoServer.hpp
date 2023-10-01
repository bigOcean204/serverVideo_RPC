#include <string>
#include <chrono>

class ServerCredentials
{

};

class IServer
{
public:
	virtual ~IServer() {}
	void Shutdown(const std::chrono::milliseconds deadline) {}
	virtual void Shutdown() {}
	virtual void Wait() {}
	virtual bool Run() {}
	virtual int SetCommunicationProtocols(const std::string& protocols) = 0;
	virtual int SetServerAddress(std::string &_address) {};
	virtual int UpdateSecurityOptions(ServerCredentials* creds = 0) = 0;
};

//class CVideoServer : public IServer
//{
//private:
//	int m_maxClientSupported;
//	std::string m_Protocol;
//	std::string m_address;
//	IClientRequestHandler* m_ClientHandler;
//	IVideoService* m_VideoService;   //trim or merge
//
//
//public:
//	template <typename T>
//	void Shutdown(const std::chrono::seconds deadline);
//	virtual void Shutdown();
//	virtual void Wait();
//	virtual bool Run();
//	virtual int SetCommunicationProtocols(const std::string& protocols);
//	virtual int SetServerAddress(std::string& _address);
//	virtual int UpdateSecurityOptions(ServerCredentials* creds = 0);
//};

