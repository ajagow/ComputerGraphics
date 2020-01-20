// user libraries
#include "PPM.h"

// include iostream and fstream
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm> 
#include <typeinfo>


// Constructor loads a filename with the .ppm extension
PPM::PPM(std::string fileName){
    // TODO:    Load and parse a ppm to get its pixel
    //          data stored properly.

  std::ifstream file(fileName);

  int lineCounter = 0;

  // if file isn't there, print out warning
    if (!file) {
        std::cout<< "unable to open file";
    }

  std::string str;

  // extract header information
  while (lineCounter < 3 && std::getline(file, str) ) {
      if(!PPM::isComment(str)) {
          std::string cleanedString = PPM::removeComment(str);
          if(lineCounter == 0) {
              if (str.compare("P3") != 0) {
                  std::cout<< "Not a P3 file";
                  break;
              }
          }
        if(lineCounter == 1) {
            std::vector<std::string> sizes = PPM::split(cleanedString);
            m_width = std::stoi(sizes[0]);
            m_height = std::stoi(sizes[1]);
          }
        if(lineCounter == 2) {
              std::cout<< "color thing: " << cleanedString;
              m_maxRGBValue = std::stoi(cleanedString);
          }

          lineCounter = lineCounter + 1;
      }
    
  }

  // extract pixels
  int counter = 0;


  m_PixelData = new unsigned char[m_width * m_height * 3];

  while (std::getline(file,str)) {
      std::vector<std::string> values = PPM::split(str);
    for (std::string value: values) {
        unsigned char val = std::stoi(PPM::removeWhiteSpace(value));
        m_PixelData[counter] = val;
        counter = counter + 1;
    }
  }

}

// Destructor clears any memory that has been allocated
PPM::~PPM(){
    delete[] m_PixelData;
}

// Saves a PPM Image to a new file.
void PPM::savePPM(std::string outputFileName){
    // TODO: Save a PPM image to disk
std::ofstream myfile;
  myfile.open (outputFileName);
  myfile << "P3\n";
  myfile << m_width << " " << m_height << "\n";
  myfile << (int)m_maxRGBValue <<"\n";

    for (int i = 0; i < m_width * m_height * 3 ; i++) {
        
        myfile << (int)m_PixelData[i] << "\n";
    }


  myfile.close();

  std::cout<<"closed: ";

}

// Darken subtracts 50 from each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken(){
    // TODO: Output a 'filtered' PPM image.

    // subtract 50 from highest val
    m_maxRGBValue = std::max(0, m_maxRGBValue - 50);


    for (int i = 0; i < m_width * m_height * 3 ; i++) {
        unsigned char value = m_PixelData[i];
        m_PixelData[i] = std::max(value-50, 0);
    
    }

    
}

// Sets a pixel to a specific R,G,B value 
void PPM::setPixel(int x, int y, int R, int G, int B){
    // TODO: Implement
    int index = (y * m_width * 3) + x * 3;

    m_PixelData[index+0] = R;
    m_PixelData[index+1] = G;
    m_PixelData[index+2] = B;
}

bool PPM::isComment(std::string line) {
    std::string::size_type found = line.find_first_not_of(" ");
    
    char foundChar = line[found];

    return foundChar == '#';
}

std::string PPM::removeComment(std::string line) {
    return line.substr(0, line.find("#"));
}

std::string PPM::removeWhiteSpace(std::string input) {
    input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;

}

std::vector<std::string> PPM::split(std::string s) {
    std::regex regex("\\s+");

    std::vector<std::string> out(
					std::sregex_token_iterator(s.begin(), s.end(), regex, -1),
					std::sregex_token_iterator()
					);
    return out;

}


