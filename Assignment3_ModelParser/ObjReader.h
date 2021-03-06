/** @file ObjReader.h
 *  @brief Class for working with PPM images
 *  
 *  Class for working with P3 PPM images specifically.
 *
 *  @author your_name_here
 *  @bug No known bugs.
 */
#ifndef OBJREADER_H
#define OBJREADER_H

#include <string>
#include <vector>

class ObjReader
{
public:
    // Constructor loads a filename with the .ppm extension
    ObjReader(std::string fileName);
    // Destructor clears any memory that has been allocated
    ~ObjReader(){};

    // Struct to represent the x, y, z values of a Vector
    struct Vector3
    {
        float x, y, z;
    };

    std::vector<float> getVertices();
    std::vector<float> getNormals();
    std::vector<unsigned int> getFaces();

    // NOTE:    You may add any helper functions you like in the
    //          private section.
private:
    // vertices of .obj
    std::vector<Vector3> vertices;
    // normal values of .obj
    std::vector<Vector3> normal;
    // vertex indices of face values of .obj
    std::vector<unsigned int> vertexIndices;

    //splits a string based on regex passed into function
    std::vector<std::string> split(std::string givenString, std::string regexMatch);
};

#endif
