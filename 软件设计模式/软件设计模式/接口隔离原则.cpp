#include<string>
#include<iostream>

using namespace std;

class DateHandle
{
public:
	virtual string dataRead() = 0;
	virtual void transformToXml() = 0;
	virtual void transformToPDF() = 0;
	virtual void createReport() = 0;
	virtual void displayReport() = 0;
};
//上述不满足接口隔离
class DateHandleRead
{
public:
	virtual string dataRead() = 0;
};
class TranformHandle
{
public:
	virtual void transformToXml() = 0;
	virtual void transformToPDF() = 0;
};
class ReportHandle
{
public:
	virtual void createReport() = 0;
	virtual void createReport() = 0;
};
class  ReportHandleImpl :ReportHandle
{
public:
	void createReport();
	void createReport();
};