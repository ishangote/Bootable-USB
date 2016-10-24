#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;


void format(string path)
{
	cout<<"Formatting the USB....\n";
	string um = "unmount "+path;
	system(um.c_str());
	string um1 = "mkfs.ext4 "+path;		//For MS Dos os make "mkfs.vfat"(FAT 32/64)
	system(um1.c_str());
	return;
}

void isocopy(string path,string path1)
{
	cout<<"Making USB bootable....\n";
	string str1 = "dd if="+path1;
	string str2 = " of="+path;
	string str3 = str1 + str2;
	system(str3.c_str());
}

int main()
{
string path, path1;

system("lsblk");

cout<<"Enter USB path: ";
cin>>path;

cout<<"Enter ISO path: ";		//ISO image of the OS you want to boot in.
cin>>path1;

format(path);
isocopy(path,path1);
return 0;

}
