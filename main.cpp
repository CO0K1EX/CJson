#include <iostream>
#include "Client.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

std::string getFieldFromJson(std::string json, std::string field);

int main()
{
	system("title CJson");
	std::cout << "\n CJson version 1.0.0 || Creator By CO0K1E" << std::endl << std::endl;
	std::cout << "\n Example ---> ip-api.com" << std::endl;
	std::string inputs;
	std::cout << "\n Input: ";
	std::cin >> inputs;
	Client client;
	std::string res = client.getResponse(inputs);

	Sleep(2300);
	system("cls");

	std::cout << "Result:" << std::endl << std::endl;

	std::cout << "Ip: " << getFieldFromJson(res, "query") << std::endl;
	std::cout << "Status: " << getFieldFromJson(res, "status") << std::endl;
	std::cout << "Country: " << getFieldFromJson(res, "country") << std::endl;
	std::cout << "CountryCode: " << getFieldFromJson(res, "countryCode") << std::endl;
	std::cout << "Region: " << getFieldFromJson(res, "region") << std::endl;
	std::cout << "RegionName: " << getFieldFromJson(res, "regionName") << std::endl;
	std::cout << "City: " << getFieldFromJson(res, "city") << std::endl;
	std::cout << "Zip: " << getFieldFromJson(res, "zip") << std::endl;
	std::cout << "Lat: " << getFieldFromJson(res, "lat") << std::endl;
	std::cout << "Lon: " << getFieldFromJson(res, "lon") << std::endl;
	std::cout << "Timezone: " << getFieldFromJson(res, "timezone") << std::endl;
	std::cout << "Isp: " << getFieldFromJson(res, "isp") << std::endl;
	std::cout << "Org: " << getFieldFromJson(res, "org") << std::endl;
	std::cout << "As: " << getFieldFromJson(res, "as") << std::endl << std::endl;

	system("pause");
	return 0;
}

std::string getFieldFromJson(std::string json, std::string field)
{
	std::stringstream jsonEncoded(json);
	boost::property_tree::ptree root;
	boost::property_tree::read_json(jsonEncoded, root);

	if (root.empty())
		return "";

	return root.get<std::string>(field);
}