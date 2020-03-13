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
#include <map>
#include "MtlFileReader.h"

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

    // Struct to represent the s,t values of a Vector Texture
    struct Vector2
    {
        float s, t;

        bool operator<(const Vector2 &ob) const
        {
            return s < ob.s || (s == ob.s && t < ob.t);
        }
    };

    struct VertexData{
        float x,y,z;
        float s,t;

        VertexData(float _x, float _y, float _z, float _s, float _t): x(_x),y(_y),z(_z),s(_s),t(_t) { }
        
        // Tests if two VertexData are equal
        bool operator== (const VertexData &rhs){
            if( (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (s == rhs.s) && (t == rhs.t) ){
                return true;
            }
            return false;
        }
    };



    std::vector<float> getVertices();
    std::vector<float> getNormals();
    std::vector<float> getVerticesAndTextures();
    std::vector<VertexData> getVerticesAndTextures2();
    std::vector<unsigned int> getFaces();
    std::string getMtlFilepath();

    // NOTE:    You may add any helper functions you like in the
    //          private section.
private:
    // filepath info
    std::string objFilePath;
    std::string mtlFilePath;

    // vertices of .obj
    std::vector<Vector3> vertices;
    // normal values of .obj
    std::vector<Vector3> normal;
    // texture values of .obj
    std::vector<Vector2> textures;
    // vertex indices of face values of .obj
    std::vector<unsigned int> vertexIndices;

    // vertex and texture data for buffer
    std::vector<float> vertexAndTextures;


    std::map<ObjReader::Vector2, int> vectorVals;

    //splits a string based on regex passed into function
    std::vector<std::string> split(std::string givenString, std::string regexMatch);
};

#endif
