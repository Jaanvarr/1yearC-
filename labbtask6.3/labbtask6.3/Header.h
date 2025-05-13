#pragma once

#include <iostream>
#include <cstring>
#include <time.h>
#include <map>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

class BASEofALL			//это основной класс. Его наследнки -- BaseOfThree и Ellipse
{
protected:
	bool visible;
	double Size_height, Size_width;
	double CoordinateX, CoordinateY;
public:
	BASEofALL() : visible(0), Size_height(0), Size_width(0), CoordinateX(0), CoordinateY(0) {}

	BASEofALL(bool vis, double h, double w, double x, double y)
	{
		visible = vis;
		Size_height = h;
		Size_width = w;
		CoordinateX = x;
		CoordinateY = y;
	}

	virtual ~BASEofALL()
	{
		//std::cout << "Destructed BaseOfAll class." << std::endl;
	}

	BASEofALL(const BASEofALL& other)
	{
		visible = other.visible;
		Size_height = other.Size_height;
		Size_width = other.Size_width;
		CoordinateX = other.CoordinateX;
		CoordinateY = other.CoordinateY;
	}

	virtual BASEofALL& operator=(const BASEofALL& other)
	{
		if (this != &other)
		{
			visible = other.visible;
			Size_height = other.Size_height;
			Size_width = other.Size_width;
			CoordinateX = other.CoordinateX;
			CoordinateY = other.CoordinateY;
		}
		return *this;
	}

	virtual BASEofALL& operator=(BASEofALL&& other) noexcept {
		if (this != &other)
		{
			visible = other.visible;
			Size_height = other.Size_height;
			Size_width = other.Size_width;
			CoordinateX = other.CoordinateX;
			CoordinateY = other.CoordinateY;

			other.visible = 0;
			other.Size_height = 0;
			other.Size_width = 0;
			other.CoordinateX = 0;
			other.CoordinateY = 0;
		}
		return *this;
	}

	BASEofALL(BASEofALL&& other) noexcept :
		visible(other.visible), Size_height(other.Size_height),
		Size_width(other.Size_width),
		CoordinateX(other.CoordinateX), CoordinateY(other.CoordinateY)
	{
		other.visible = 0;
		other.Size_height = 0;
		other.Size_width = 0;
		other.CoordinateX = 0;
		other.CoordinateY = 0;
	}

	bool getvis() { return visible; }
	double getHeight() { return Size_height; }
	double getWidth() { return Size_width; }
	double getX() { return CoordinateX; }
	double getY() { return CoordinateY; }

public:

	/*virtual void fillRand(std::istream& in)
	{
		visible = rand() % 2;
		Size_height = rand() % 2561;
		Size_width = rand() % 2561;
		CoordinateX = rand() % 2561;
		CoordinateY = rand() % 2561;
	}

	virtual void fill(std::istream& in)
	{
		std::cout << "Enter basic fields: " << std::endl;
		std::cout << "Visibility (0/1): ";
		in >> visible;
		if (visible != 1 && visible != 0)
		{
			std::cout << "Error." << std::endl;
			return;
		}
		std::cout << "Height: ";


		in >> Size_height;
		if (Size_height > 2560 || Size_height < 1) {

			std::cout << "Restricted value. Enter again." << std::endl;
			return;
		}

		std::cout << "Width: ";
		in >> Size_width;
		if (Size_width > 2560 || Size_width < 1)
		{
			std::cout << "Restricted value. Enter again." << std::endl;
			return;
		}
		std::cout << "X coord: ";

		in >> CoordinateX;
		if (CoordinateX > 2560 || CoordinateX < 1)
		{

			std::cout << "Restricted value. Enter again." << std::endl;
			return;
		}
		std::cout << "Y coord: ";

		in >> CoordinateY;
		if (CoordinateY > 2560 || CoordinateY < 1) {

			std::cout << "Restricted value. Enter again." << std::endl;
			return;
		}
	}*/
	/*virtual void Print(std::ostream& os) const
	{
		os << "Class Type: " << get_type() << std::endl;
		os << "Visibility: " << visible << std::endl;
		os << "Height: " << Size_height << std::endl;
		os << "Width: " << Size_width << std::endl;
		os << "X coordinate: " << CoordinateX << std::endl;
		os << "Y coordinate: " << CoordinateY << std::endl;
	}*/


public:
	virtual const char* get_type() const
	{
		return "BaseOfAll";
	}

	virtual BASEofALL* Clone() const = 0;

	friend std::istream& operator>>(std::istream& in, BASEofALL& base)
	{
		base.BASE_input(in); // !!!!!!! менять ручной неручной ввод тут
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const BASEofALL& base)
	{
		base.BASE_output(out);
		return out;
	}

	virtual bool BASE_input(std::istream&);
	virtual bool BASE_output(std::ostream&) const;
	virtual bool BASE_input_file(std::istream&);
	virtual bool BASE_output_file(std::ostream&) const;

};



class BASEofTHREE : public BASEofALL {	//это класс-наследник BaseofAll. Его потомки -- BaseOfTwo м Button
protected:
	char Text[80];

public:

	BASEofTHREE() : BASEofALL()
	{
		Text[0] = '\0';
	}

	BASEofTHREE(const char* txt, bool vis, double h, double w, double x, double y)
		: BASEofALL(vis, h, w, x, y)
	{

		strncpy_s(Text, txt, sizeof(Text) - 1);
		Text[sizeof(Text) - 1] = '\0';
	}

	BASEofTHREE(const BASEofTHREE& base) : BASEofALL(base)
	{
		strncpy_s(Text, base.Text, sizeof(Text) - 1);
		Text[sizeof(Text) - 1] = '\0';
	}

	BASEofTHREE(BASEofTHREE&& base) noexcept : BASEofALL(base)
	{


		strncpy_s(Text, base.Text, sizeof(Text) - 1);
		Text[sizeof(Text) - 1] = '\0';

		base.Text[0] = 0;

	}

	BASEofTHREE& operator=(const BASEofTHREE& base)
	{
		BASEofALL::operator=(base);
		strncpy_s(Text, base.Text, sizeof(Text) - 1);
		Text[sizeof(Text) - 1] = '\0';

	}

	BASEofTHREE& operator=(BASEofTHREE&& base) noexcept
	{
		BASEofALL::operator=(base);
		strncpy_s(Text, base.Text, sizeof(Text) - 1);
		Text[sizeof(Text) - 1] = '\0';

		base.Text[0] = 0;

	}

public:
	virtual ~BASEofTHREE() override
	{
		//std::cout << "Destructed: BaseOfThree." << std::endl;
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofALL::fillRand(in);
		int temp = rand() % 20 + 2;
		for (int i = 0; i < temp; i++)
		{
			Text[i] = rand() % 25 + 65;
		}
		Text[temp] = 0;
	}

	virtual void fill(std::istream& in) override
	{
		BASEofALL::fill(in);
		std::cout << "Enter Text: ";
		in >> Text;
	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofALL::Print(out);
		std::cout << "Text: " << Text << std::endl;
	}*/
	virtual const char* get_type() const override
	{
		return "BaseOfThree";
	}

	virtual BASEofTHREE* Clone() const override
	{
		return new BASEofTHREE(*this);
	}

	const char* getText() const { return Text; }

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;



};

class BASEofTWO : public BASEofTHREE //это потомок  BaseOfThree. его потомки -- HyperLinkLabel, TextBox
{
	int Color[3];


public:

	BASEofTWO() : BASEofTHREE()
	{
		for (int i = 0; i < 3; i++)
		{
			Color[i] = 0;
		}
	}

	BASEofTWO(const int* color, const char* txt, bool vis, double h, double w, double x, double y)
		: BASEofTHREE(txt, vis, h, w, x, y)
	{
		for (int i = 0; i < 3; i++)
		{
			Color[i] = color[i];
		}
	}

	BASEofTWO(const BASEofTWO& base) : BASEofTHREE(base)
	{
		for (int i = 0; i < 3; i++)
		{
			Color[i] = base.Color[i];
		}
	}

	BASEofTWO(BASEofTWO&& base) noexcept : BASEofTHREE(base)
	{
		for (int i = 0; i < 3; i++)
		{
			Color[i] = base.Color[i];
			base.Color[i] = 0;
		}
	}

	BASEofTWO& operator=(const BASEofTWO& base)
	{
		BASEofTHREE::operator=(base);
		for (int i = 0; i < 3; i++)
		{
			Color[i] = base.Color[i];
		}
	}

	BASEofTWO& operator=(BASEofTWO&& base) noexcept
	{
		BASEofTHREE::operator=(base);
		for (int i = 0; i < 3; i++)
		{
			Color[i] = base.Color[i];
			base.Color[i] = 0;
		}
	}

public:
	virtual ~BASEofTWO() override
	{
		//std::cout << "Destructed BaseOfTwo." << std::endl;
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofTHREE::fillRand(in);
		for (int i = 0; i < 3; i++)
		{
			Color[i] = rand() % 256;
		}
	}

	virtual void fill(std::istream& in) override
	{
		BASEofTHREE::fill(in);
		std::cout << "Enter RGB: ";
		int i = 0;

		while (i < 3)
		{
			in >> Color[i];
			if (Color[i] <= 255 || Color[i] > -1) {
				i++;
			}
			else {
				std::cout << "Error! Enter again." << std::endl;
			}

		}
		std::cout << std::endl;;
	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofTHREE::Print(out);
		std::cout << "RGB: ";
		for (int i = 0; i < 3; i++)
		{
			std::cout << Color[i] << ", ";
		}
		std::cout << std::endl;
	}*/

	virtual const char* get_type() const override
	{
		return "BaseOfTwo";
	}

	const int* getColor() const { return Color; }

	virtual BASEofTWO* Clone() const override
	{
		return new BASEofTWO(*this);
	}

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;

};

class Ellipse : public BASEofALL
{
	int FillColor[3];
	int BorderColor[3];
public:

	Ellipse() : BASEofALL()
	{
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = 0;
			BorderColor[i] = 0;
		}
	}

	Ellipse(const int* fc, const int* bc, bool vis, double h, double w, double x, double y)
		: BASEofALL(vis, h, w, x, y)
	{
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = fc[i];
			BorderColor[i] = bc[i];
		}
	}

	Ellipse(const Ellipse& ell) : BASEofALL(ell)
	{
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = ell.FillColor[i];
			BorderColor[i] = ell.BorderColor[i];
		}
	}

	Ellipse(Ellipse&& ell) noexcept : BASEofALL(ell)
	{
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = ell.FillColor[i];
			ell.FillColor[i] = 0;
			BorderColor[i] = ell.BorderColor[i];
			ell.BorderColor[i] = 0;
		}
	}

	Ellipse& operator=(const Ellipse& ell)
	{
		BASEofALL::operator=(ell);
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = ell.FillColor[i];
			BorderColor[i] = ell.BorderColor[i];
		}
	}

	Ellipse& operator=(Ellipse&& ell) noexcept
	{
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = ell.FillColor[i];
			ell.FillColor[i] = 0;
			BorderColor[i] = ell.BorderColor[i];
			ell.BorderColor[i] = 0;
		}
	}

public:
	virtual ~Ellipse() override
	{
		//std::cout << "Destructed Ellipse." << std::endl;
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofALL::fillRand(in);
		for (int i = 0; i < 3; i++)
		{
			FillColor[i] = rand() % 255 + 1;
			BorderColor[i] = rand() % 256;
		}
	}

	virtual void fill(std::istream& in) override
	{
		BASEofALL::fill(in);
		std::cout << "Enter RGB for the filling color: ";
		int i = 0;

		while (i < 3)
		{
			in >> FillColor[i];
			if (FillColor[i] <= 255 || FillColor[i] > -1) {
				i++;
			}
			else {
				std::cout << "Error! Enter again." << std::endl;
			}

		}
		std::cout << "Enter RGB for the border color: ";
		i = 0;

		while (i < 3)
		{
			in >> BorderColor[i];
			if (BorderColor[i] <= 255 || BorderColor[i] > -1) {
				i++;
			}
			else {
				std::cout << "Error! Enter again." << std::endl;
			}

		}
	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofALL::Print(out);
		out << "Filling RGB: [" << FillColor[0] << ", " << FillColor[1] << ", " << FillColor[2] << "] "
			<< "Border RGB: [" << BorderColor[0] << ", " << BorderColor[1] << ", " << BorderColor[2] << "]" <<
			std::endl;
	}*/

	virtual const char* get_type() const override
	{
		return "Ellipse";
	}

	virtual Ellipse* Clone() const override
	{
		return new Ellipse(*this);
	}

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;
};

class HyperLinkLabel : public BASEofTWO    //тут наверное стоит прописать оператор<<
{
	char URL[80];
public:
	HyperLinkLabel() : BASEofTWO()
	{
		URL[0] = '\0';
	}



	HyperLinkLabel(const char* url, const int* color, const char* txt, bool vis, double h, double w, double x, double y)
		: BASEofTWO(color, txt, vis, h, w, x, y)
	{
		strncpy_s(URL, url, sizeof(URL) - 1);
		URL[sizeof(URL) - 1] = '\0';
	}

	HyperLinkLabel(const HyperLinkLabel& hype) : BASEofTWO(hype)
	{
		strncpy_s(URL, hype.URL, sizeof(URL) - 1);
		URL[sizeof(URL) - 1] = '\0';
	}

	HyperLinkLabel(HyperLinkLabel&& hype) noexcept : BASEofTWO(hype)
	{
		strncpy_s(URL, hype.URL, sizeof(URL) - 1);
		URL[sizeof(URL) - 1] = '\0';

		hype.URL[0] = 0;
	}

	HyperLinkLabel& operator=(const HyperLinkLabel& hype)
	{
		BASEofTWO::operator=(hype);
		strncpy_s(URL, hype.URL, sizeof(URL) - 1);
		URL[sizeof(URL) - 1] = '\0';
	}

	HyperLinkLabel& operator=(HyperLinkLabel&& hype) noexcept
	{
		BASEofTWO::operator=(hype);
		strncpy_s(URL, hype.URL, sizeof(URL) - 1);
		URL[sizeof(URL) - 1] = '\0';

		hype.URL[0] = 0;
	}

public:
	virtual ~HyperLinkLabel() override
	{
		//std::cout << "Destructed HyperLinkLabel." << std::endl;;
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofTWO::fillRand(in);
		int temp = rand() % 15 + 2;
		for (int i = 0; i < temp; i++)
		{
			URL[i] = rand() % 25 + 65;
		}
		URL[temp] = 0;
	}

	virtual void fill(std::istream& in)
	{
		BASEofTWO::fill(in);
		std::cout << "Enter URL: ";
		in >> URL;

	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofTWO::Print(out);
		out << "URL: ";
		out << URL << std::endl;
	}*/

	virtual const char* get_type() const override
	{
		return "HyperLinkLabel";
	}

	virtual HyperLinkLabel* Clone() const override
	{
		return new HyperLinkLabel(*this);
	}

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;
};

class TextBox : public BASEofTWO			//тут наверное стоит прописать оператор<<
{
	bool Readonly;
public:

	TextBox() : BASEofTWO()
	{
		Readonly = 1;
	}

	TextBox(bool read, const char* txt, const int* color, bool vis, double h, double w, double x, double y)
		: BASEofTWO(color, txt, vis, h, w, x, y)
	{
		Readonly = read;
	}

	TextBox(const TextBox& txt) : BASEofTWO(txt)
	{
		Readonly = txt.Readonly;
	}

	TextBox(TextBox&& txt) noexcept : BASEofTWO(txt)
	{
		Readonly = txt.Readonly;
		txt.Readonly = 0;
	}

	TextBox& operator=(const TextBox& txt)
	{
		BASEofTWO::operator=(txt);
		Readonly = txt.Readonly;

	}

	TextBox& operator=(TextBox&& txt) noexcept
	{
		BASEofTWO::operator=(txt);
		Readonly = txt.Readonly;
		txt.Readonly = 0;

	}

public:
	virtual ~TextBox() override
	{
		//std::cout << "Destructed TextBox.";
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofTWO::fillRand(in);
		Readonly = rand() % 2;
	}

	virtual void fill(std::istream& in)
	{
		BASEofTWO::fill(in);
		std::cout << "Enter Readonly feature: ";
		while (1) {
			in >> Readonly;
			if (Readonly == 1 || Readonly == 0)
			{
				break;
			}
			else
			{
				std::cout << "Error! Enter again." << std::endl;
			}
		}

	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofTWO::Print(out);
		out << "Readonly: " << Readonly << std::endl;
	}*/

	virtual const char* get_type() const override
	{
		return "TextBox";
	}

	virtual TextBox* Clone() const override
	{
		return new TextBox(*this);
	}

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;
};

class Button : public BASEofTHREE			//тут наверное стоит прописать оператор<<
{
	char ToolTipText[80];
public:

	Button() : BASEofTHREE()
	{
		ToolTipText[0] = '\0';
	}

	Button(const char* tool, const char* txt, bool vis, double h, double w, double x, double y)
		: BASEofTHREE(txt, vis, h, w, x, y)
	{
		strncpy_s(ToolTipText, tool, sizeof(ToolTipText) - 1);
		ToolTipText[sizeof(ToolTipText) - 1] = '\0';
	}

	Button(const Button& button) : BASEofTHREE(button)
	{
		strncpy_s(ToolTipText, button.ToolTipText, sizeof(ToolTipText) - 1);
		ToolTipText[sizeof(ToolTipText) - 1] = '\0';
	}

	Button(Button&& button) noexcept : BASEofTHREE(button)
	{
		strncpy_s(ToolTipText, button.ToolTipText, sizeof(ToolTipText) - 1);
		ToolTipText[sizeof(ToolTipText) - 1] = '\0';

		button.ToolTipText[0] = 0;
	}

	Button& operator=(const Button& button)
	{
		BASEofTHREE::operator=(button);
		strncpy_s(ToolTipText, button.ToolTipText, sizeof(ToolTipText) - 1);
		ToolTipText[sizeof(ToolTipText) - 1] = '\0';
	}

	Button& operator=(Button&& button) noexcept
	{
		BASEofTHREE::operator=(button);
		strncpy_s(ToolTipText, button.ToolTipText, sizeof(ToolTipText) - 1);
		ToolTipText[sizeof(ToolTipText) - 1] = '\0';

		button.ToolTipText[0] = 0;
	}


	virtual ~Button() override
	{
		//std::cout << "Destructed Button.";
	}

	/*virtual void fillRand(std::istream& in) override
	{
		BASEofTHREE::fillRand(in);
		int temp = rand() % 15 + 2;
		for (int i = 0; i < temp; i++)
		{
			ToolTipText[i] = rand() % 25 + 65;
		}
		ToolTipText[temp] = 0;
	}

	virtual void fill(std::istream& in)
	{
		BASEofTHREE::fill(in);
		std::cout << "Enter ToolTipText: ";
		in >> ToolTipText;
	}*/

	/*virtual void Print(std::ostream& out) const override
	{
		BASEofTHREE::Print(out);
		out << "ToolTipText: " << ToolTipText << std::endl;
	}*/

	virtual const char* get_type() const override
	{
		return "Button";
	}

	virtual Button* Clone() const override
	{
		return new Button(*this);
	}

	virtual bool BASE_input(std::istream&) override;
	virtual bool BASE_output(std::ostream&) const override;
	virtual bool BASE_input_file(std::istream&) override;
	virtual bool BASE_output_file(std::ostream&) const override;
};

BASEofALL* CreateBase(const char* typeName);


class BASE_Factory
{
	std::map<std::string, BASEofALL*> map_BASE_templs;

	void AddBASEtype(BASEofALL* pointerBASE)
	{
		map_BASE_templs.insert(std::pair<std::string, BASEofALL*>(pointerBASE->get_type(), pointerBASE));
	}
public:
	BASE_Factory()
	{
		AddBASEtype(new Ellipse());
		AddBASEtype(new HyperLinkLabel());
		AddBASEtype(new TextBox());
		AddBASEtype(new Button());
	}

	BASEofALL* Create(const char* typeName);
	
	~BASE_Factory()
	{
		for (std::map<std::string, BASEofALL*> ::iterator it = map_BASE_templs.begin(); it != map_BASE_templs.end(); ++it)
			delete it->second;
		map_BASE_templs.clear();
	}
};
//int main()
//{
//
//	const char* text = "brrrrr";
//
//
//	BASEofALL baseX;
//
//	std::cin >> baseX;
//	std::cout << std::endl;
//	std::cout << baseX;
//	//хз наверное надо какой-то тестбенч сделать но я устал
//	return 0;
//
//}