#include<string>
#include<iostream>

using namespace std;

class Image
{
public:
	Image(string name):m_imageName(name){}
	virtual ~Image() {}
	virtual void Show() {}
protected:
	string m_imageName;
};
class BigImage :public Image
{
public:
	BigImage(string name):Image(name){}
	~BigImage() {};
	void Show() { cout << "Big Image: " << m_imageName << endl; }
};
class BigImageProxy :public Image
{
public:
	BigImageProxy(string name):Image(name),m_bigImage(nullptr){}
	~BigImageProxy(){}
	void Show()
	{
		if (m_bigImage == nullptr)
			m_bigImage = make_shared<BigImage>(m_imageName);
		m_bigImage->Show();
	}
private:
	shared_ptr<BigImage> m_bigImage;
};
int main()
{
	shared_ptr<Image> image = make_shared<BigImageProxy>("proxy.jpg");
	image->Show();
	return 0;
}