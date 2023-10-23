#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class NetworkDevice
{
public:
	virtual string getType() =0;
	virtual void use() =0;
};
class Switch:public NetworkDevice
{
public:
	Switch(string type):type(type){}
	string getType() { return type; }
	void use() { cout << "Linked by switch,type is" << type << endl;; }
private:
	string type;
};
class Hub :public NetworkDevice
{
public:
	Hub(string type) :type(type) {}
	string getType() { return type; }
	void use() { cout << "Linked by Hub,type is" << type<<endl; }
private: 
	string type;
};

class DeviceFactory
{
public:
	DeviceFactory()
	{
		shared_ptr<NetworkDevice> nd1 = make_shared<Switch>("Cisco-WS-c295024");
		shared_ptr<NetworkDevice> nd2 = make_shared<Hub>("TP-link-HF8M");
		devices.push_back(nd1);
		devices.push_back(nd2);
	}
	shared_ptr<NetworkDevice> getNetworkDevice(string type)
	{
		transform(type.begin(), type.end(), type.begin(), ::tolower);
		if (type == "cisco")
		{
			totalTerminal++;
			return devices[0];
		}
		else if (type == "tp")
		{
			totalTerminal++;
			return devices[1];
		}
		else
			return nullptr;
	}
	int getTotalDevice() { return devices.size(); }
	int getTotalTerminal() { return totalTerminal; }
private:
	vector<shared_ptr<NetworkDevice>> devices;
	int totalTerminal = 0;
};
int main()
{
	shared_ptr<NetworkDevice> nd1, nd2, nd3, nd4, nd5;
	DeviceFactory df;
	nd1 = df.getNetworkDevice("cisco");
	nd1->use();
	nd2 = df.getNetworkDevice("cisco");
	nd2->use();
	nd3 = df.getNetworkDevice("cisco");
	nd3->use();
	nd4 = df.getNetworkDevice("tp");
	nd4->use();
	nd5 = df.getNetworkDevice("tp");
	nd5->use();
	cout << "Total Device" << df.getTotalDevice() << endl;;
	cout << "TotalTerminal" << df.getTotalTerminal() << endl;;
}