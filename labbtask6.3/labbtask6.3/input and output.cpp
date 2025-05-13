#include "Header.h"

bool BASEofALL::BASE_input(std::istream& in)
{
	visible = rand() % 2;
	Size_height = rand() % 2561;
	Size_width = rand() % 2561;
	CoordinateX = rand() % 2561;
	CoordinateY = rand() % 2561;

	return in.good();
}

bool BASEofALL::BASE_input_file(std::istream& in)
{
	in >> visible;
	in >> Size_height; in >> Size_width;
	in >> CoordinateX; in >> CoordinateY;
	std::string s; 
	std::getline(in, s);
	return in.good();
}

bool BASEofALL::BASE_output(std::ostream& os) const
{
	os << "Class Type: " << get_type() << std::endl;
	os << "Visibility: " << visible << std::endl;
	os << "Height: " << Size_height << std::endl;
	os << "Width: " << Size_width << std::endl;
	os << "X coordinate: " << CoordinateX << std::endl;
	os << "Y coordinate: " << CoordinateY << std::endl;
	return os.good();
}

bool BASEofALL::BASE_output_file(std::ostream& out) const
{
	out << get_type() << std::endl;
	out << visible << std::endl;
	out << Size_height << std::endl;
	out << Size_width << std::endl;
	out << CoordinateX << std::endl;
	out << CoordinateY << std::endl;
	return out.good();
}

bool BASEofTHREE::BASE_input(std::istream& in)
{
	BASEofALL::BASE_input(in);
	int temp = rand() % 20 + 2;
	for (int i = 0; i < temp; i++)
	{
		Text[i] = rand() % 25 + 65;
	}
	Text[temp] = 0;
	return in.good();
}

bool BASEofTHREE::BASE_input_file(std::istream& in)
{
	BASEofALL::BASE_input_file(in);
	in >> Text;
	std::string s; std::getline(in, s);
	return in.good();
}

bool BASEofTHREE::BASE_output(std::ostream& out) const
{
	BASEofALL::BASE_output(out);
	out << "Text: " << Text << std::endl;
	return out.good();
}

bool BASEofTHREE::BASE_output_file(std::ostream& out) const
{
	BASEofALL::BASE_output_file(out);
	out << Text << std::endl;
	return out.good();
}

bool BASEofTWO::BASE_input(std::istream& in)
{
	BASEofTHREE::BASE_input(in);
	
	for (int i = 0; i < 3; i++)
	{
		Color[i] = rand() % 256;
	}
	
	return in.good();
}

bool BASEofTWO::BASE_input_file(std::istream& in)
{
	BASEofTHREE::BASE_input_file(in);
	in >> Color[0]; in >> Color[1]; in >> Color[2];
	std::string s; std::getline(in, s);
	return in.good();
}

bool BASEofTWO::BASE_output(std::ostream& out) const
{
	BASEofTHREE::BASE_output(out);
	out << "RGB: [" << Color[0] << ", " << Color[1] <<", " << Color[2] << "]" << std::endl;
	return out.good();
}

bool BASEofTWO::BASE_output_file(std::ostream& out) const
{
	BASEofTHREE::BASE_output_file(out);
	out << Color[0] << ", " << Color[1] << ", " << Color[2] << std::endl;
	return out.good();
}


bool Ellipse::BASE_input(std::istream& in)
{
	BASEofALL::BASE_input(in);
	for (int i = 0; i < 3; i++)
	{
		FillColor[i] = rand() % 256;
		BorderColor[i] = rand() % 256;
	}
	return in.good();
}

bool Ellipse::BASE_input_file(std::istream& in)
{
	BASEofALL::BASE_input_file(in);
	in >> FillColor[0]; in >> FillColor[1]; in >> FillColor[2];
	in >> BorderColor[0]; in >> BorderColor[1]; in >> BorderColor[2];
	std::string s; std::getline(in, s);
	return in.good();
}

bool Ellipse::BASE_output(std::ostream& out) const
{
	BASEofALL::BASE_output(out);
	out << "Filling RGB: [" << FillColor[0] << ", " << FillColor[1] << ", " << FillColor[2] << "]" << std::endl;
	out << "Border RGB: [" << BorderColor[0] << ", " << BorderColor[1] << ", " << BorderColor[2] << "]" << std::endl;
	return out.good();
}

bool Ellipse::BASE_output_file(std::ostream& out) const
{
	BASEofALL::BASE_output_file(out);
	out << FillColor[0] << ", " << FillColor[1] << ", " << FillColor[2] << std::endl;
	out << BorderColor[0] << ", " << BorderColor[1] << ", " << BorderColor[2] << std::endl;
	return out.good();
}



bool HyperLinkLabel::BASE_input(std::istream& in)
{
	BASEofTHREE::BASE_input(in);
	int temp = rand() % 20 + 2;
	for (int i = 0; i < temp; i++)
	{
		URL[i] = rand() % 25 + 65;
	}
	URL[temp] = 0;
	return in.good();
}

bool HyperLinkLabel::BASE_input_file(std::istream& in)
{
	BASEofTHREE::BASE_input_file(in);
	in >> URL;
	std::string s; std::getline(in, s);
	return in.good();
}

bool HyperLinkLabel::BASE_output(std::ostream& out) const
{
	BASEofTHREE::BASE_output(out);
	out << "URL: " << URL << std::endl;
	return out.good();
}

bool HyperLinkLabel::BASE_output_file(std::ostream& out) const
{
	BASEofTHREE::BASE_output_file(out);
	out << URL << std::endl;
	return out.good();
}



bool TextBox::BASE_input(std::istream& in)
{
	BASEofTWO::BASE_input(in);
	Readonly = rand() % 2;
	return in.good();
}

bool TextBox::BASE_input_file(std::istream& in)
{
	BASEofTWO::BASE_input_file(in);
	in >> Readonly;
	std::string s; std::getline(in, s);
	return in.good();
}

bool TextBox::BASE_output(std::ostream& out) const
{
	BASEofTWO::BASE_output(out);
	out << "Readonly: " << Readonly << std::endl;
	return out.good();
}

bool TextBox::BASE_output_file(std::ostream& out) const
{
	BASEofTWO::BASE_output_file(out);
	out << Readonly << std::endl;
	return out.good();
}



bool Button::BASE_input(std::istream& in)
{
	BASEofTHREE::BASE_input(in);
	int temp = rand() % 20 + 2;
	for (int i = 0; i < temp; i++)
	{
		ToolTipText[i] = rand() % 25 + 65;
	}
	ToolTipText[temp] = 0;
	return in.good();
}

bool Button::BASE_input_file(std::istream& in)
{
	BASEofTHREE::BASE_input_file(in);
	in >> ToolTipText;
	std::string s; std::getline(in, s);
	return in.good();
}

bool Button::BASE_output(std::ostream& out) const
{
	BASEofTHREE::BASE_output(out);
	out << "ToolTipText: " << ToolTipText << std::endl;
	return out.good();
}

bool Button::BASE_output_file(std::ostream& out) const
{
	BASEofTHREE::BASE_output_file(out);
	out << ToolTipText << std::endl;
	return out.good();
}


BASEofALL* BASE_Factory::Create(const char* typeName)
{
	std::map<std::string, BASEofALL*>::iterator ITERATOR;
	ITERATOR = map_BASE_templs.find(typeName);
	if (ITERATOR == map_BASE_templs.end())
		return nullptr;
	return ITERATOR->second->Clone();

}

BASEofALL* CreateBase(const char* typeName)
{
	static BASEofALL* g_vElemTempls[4] =
	{ new Ellipse(), new HyperLinkLabel(), new TextBox(), new Button() };
	for (int i = 0; i < 3; i++)
	{
		BASEofALL* pointer = g_vElemTempls[i];
		if (strcmp(pointer->get_type(), typeName) == 0)
			return pointer->Clone();

	}
	return nullptr;
}