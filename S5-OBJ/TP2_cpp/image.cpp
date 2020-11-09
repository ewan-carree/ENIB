#include "image.hpp"

namespace tp2
{
	Image::Image(std::string name, int width, int height, bool rdmPix) : name_{name}, width_{width}, height_{height}, pixels_{}
	{
		int size = height*width;
		//pixels_.resize(size);

		if (!rdmPix)
		{
			for (int i = 0; i < size; ++i)
			{
				pixels_.push_back(Color());
			}
		}

		else
		{
			std::default_random_engine rndGen{std::random_device{}()};
			std::uniform_int_distribution<int> component{0, 255};
			for (int i = 0; i < size; ++i)
			{
				pixels_.push_back(Color(uchar(component(rndGen)), uchar(component(rndGen)), uchar(component(rndGen))));
			}
			
		}
	}

	Image::Image(std::string path, RGBimage): name_{imageName(path)}, width_{}, height_{}, pixels_{}  
	{ 
		std::ifstream input(path);   
		if(!input) 
		{    
			throw std::runtime_error("cannot read from file " + path);
		}

		std::string P3;
		int c;
		input >> P3 >> width_ >> height_ >> c;

		if((P3!="P3")||(c!=255))
		{
			throw std::runtime_error("bad header in " + name_);
		}

		int r,g,b;
		for (int i = 0; i < width_*height_; i++)
		{
			input >> r;
			input >> g;
			input >> b;
			pixels_.push_back(Color(uchar(r), uchar(g), uchar(b)));
		}
	}

	Image::Image(std::string path, YUVimage): Image(imageName(path), 640, 480, false)
	{
		std::ifstream input(path, std::ios::binary);
		if(!input)
		{
			throw std::runtime_error("cannot read from file " + name_);
		}

		const int byteCount = width_*height_*4/2; // 4 bytes for 2 pixels
		std::vector<uchar> bytes(byteCount);
		
		input.read((char*)bytes.data(), byteCount);
		
		int j=0;
		for(int i=0; i<byteCount; i+=4) {
			const uchar y0=bytes[i+0], u=bytes[i+1], y1=bytes[i+2], v=bytes[i+3];
			pixels_[j++] = RGBfromYUV(y0,u,v);
			pixels_[j++] = RGBfromYUV(y1,u,v);
		}  
	}

	std::ostream& operator<<(std::ostream& os, const Image& i1)
	{
		os << i1.name() << std::endl << i1.width() << ' ' << i1.height() << std::endl;
		for (int i = 0; i < size(i1); i++)
		{
			os << i1[i] << std::endl;
		}

		return os;
	}

	std::string imageName(std::string path)
	{
		std::string name;
		if(auto pos_point = path.find_last_of('.'); pos_point!=path.npos) 
		{    
			path.resize(pos_point);  
		}
		if(auto pos_slash = path.find_last_of('/'); pos_slash!=path.npos) 
		{    
			name = path.substr(pos_slash+1);  
		}  
	
		return name;
	}

	void save(const Image& i1)
	{
		if (size(i1) == 0)
		{
			throw std::runtime_error("There is no image");
		}

		else
		{
			std::ofstream output(i1.name()+".ppm");  
			if(!output) 
			{    
				throw std::runtime_error("cannot write to file " + i1.name());
			}

			output << "P3" << std::endl;
			output << i1.width() << ' ' << i1.height() << std::endl;
			output << "255" << std::endl;

			for (int i = 0; i < size(i1); i++)
			{
				output << int(i1[i][0]) << std::endl << int(i1[i][1]) << std::endl << int(i1[i][2]) << std::endl;
			}
			
		}
		
	}

	Image grey(const Image& i1)
	{
		Image img_grey{i1.name()+"_grey", i1.width(), i1.height(), false};
		
		for (int i = 0; i < size(i1); i++)
		{
			img_grey[i] = grey(i1[i]);
			std::cout << img_grey[i] << std::endl;
		}

		return img_grey;
		
	}

} //tp2
