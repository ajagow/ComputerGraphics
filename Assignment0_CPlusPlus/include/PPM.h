/** @file PPM.h
 *  @brief Class for working with PPM images
 *  
 *  Class for working with P3 PPM images specifically.
 *
 *  @author your_name_here
 *  @bug No known bugs.
 */
#ifndef PPM_H
#define PPM_H

#include <string>
#include <vector>

class PPM{
public:
    // Constructor loads a filename with the .ppm extension
    PPM(std::string fileName);
    // Destructor clears any memory that has been allocated
    ~PPM();
    // Saves a PPM Image to a new file.
    void savePPM(std::string outputFileName);

    // Darken subtracts 50 from each of the red, green
    // and blue color components of all of the pixels
    // in the PPM. Note that no values may be less than
    // 0 in a ppm.
    void darken();

    // Sets a pixel to a specific R,G,B value 
    void setPixel(int x, int y, int R, int G, int B);

    // Returns the raw pixel data in an array.
    // You may research what 'inline' does.
    inline unsigned char* pixelData(){ return m_PixelData; }

    // Returns image width
    inline int getWidth(){ return m_width; }

    // Returns image height
    inline int getHeight(){ return m_height; }

    // Returns maxRGB value
    inline unsigned char getMaxRBGValue() { return m_maxRGBValue; }

// NOTE:    You may add any helper functions you like in the
//          private section.
private:    
    // Store the raw pixel data here
    // Data is R,G,B format
    unsigned char* m_PixelData;
    // Store width and height of image.
    int m_width{0};
    int m_height{0};

    //store max rgb value
    unsigned char m_maxRGBValue{0};

    // checks to see if a string is a comment or not
    bool isComment(std::string line);

    // removes comments that might appear in line
    std::string removeComment(std::string line);

    // remove white space in a string
    std::string removeWhiteSpace(std::string str);

    // splits a string based on white space
    std::vector<std::string> split(std::string sizeString);
};


#endif
