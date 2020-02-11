// user libraries
#include "ObjReader.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <typeinfo>

ObjReader::ObjReader(std::string filename)
{
    std::ifstream file(filename);

    std::cout << "filename: " << filename << "\n";

    // if file isn't there, print out warning
    if (!file)
    {
        std::cout << "unable to open file";
        exit(1);
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.substr(0, 2) == "v ")
        {

            std::vector<std::string> something = ObjReader::split(line, "\\s+");
            Vector3 vertex;
            vertex.x = std::stof(something[1]);
            vertex.y = std::stof(something[2]);
            vertex.z = std::stof(something[3]);

            vertices.push_back(vertex);
        }
        else if (line.substr(0, 3) == "vn ")
        {
            std::vector<std::string> something = ObjReader::split(line, "\\s+");
            Vector3 vertex;
            vertex.x = std::stof(something[1]);
            vertex.y = std::stof(something[2]);
            vertex.z = std::stof(something[3]);

            normal.push_back(vertex);
        }
        else if (line.substr(0, 2) == "f ")
        {
            std::vector<std::string> something = ObjReader::split(line, "\\s+");

            for (int i = 1; i < something.size(); i++)
            {
                std::vector<std::string> grabbedVertices = ObjReader::split(something[i], "\/\/");
                // std::cout<< "\n hello: " << grabbedVertices[0] << ", " << grabbedVertices[1] << "\n";

                vertexIndices.push_back(std::stoi(grabbedVertices[0]));
            }
        }
        else if (line[0] == '#')
        {
            /* ignoring this line */
        }
        else
        {
            /* ignoring this line */
        }
    }
}

std::vector<float> ObjReader::getVertices()
{

    std::vector<float> ans;
    for (int i = 0; i < vertices.size(); i++)
    {

        ObjReader::Vector3 v = vertices[i];
        ans.push_back(v.x);
        ans.push_back(v.y);
        ans.push_back(v.z);
    }

    return ans;

    //     std::vector<float> ans;
    // for( unsigned int i=0; i<vertexIndices.size(); i++ ){
    //     unsigned int vertexIndex = vertexIndices[i];
    //     ObjReader::Vector3 v = vertices[ vertexIndex-1 ];
    //     ans.push_back(v.x);
    //     ans.push_back(v.y);
    //     ans.push_back(v.z);
    // }

    // std::cout<< "here!!!!\n";
    // return ans;
}

std::vector<float> ObjReader::getNormals()
{

    std::vector<float> ans;
    for (int i = 0; i < normal.size(); i++)
    {

        ObjReader::Vector3 v = normal[i];
        ans.push_back(v.x);
        ans.push_back(v.y);
        ans.push_back(v.z);
    }

    return ans;
}

std::vector<unsigned int> ObjReader::getFaces()
{
    // std::vector<ObjReader::Vector3> ans;
    // for( unsigned int i=0; i<vertexIndices.size(); i++ ){
    //     unsigned int vertexIndex = vertexIndices[i];
    //     ObjReader::Vector3 v = vertices[ vertexIndex-1 ];
    //     ans.push_back(v);
    // }

    // std::cout<< "here!!!!\n";
    // return ans;

    std::vector<unsigned int> ans;
    for (int i = 0; i < vertexIndices.size(); i++)
    {
        unsigned int vertexIndex = vertexIndices[i];
        ans.push_back(vertexIndex - 1);
    }

    return ans;
}

std::vector<unsigned int> ObjReader::getLineFaces()
{

    std::vector<unsigned int> ans;
    for (int i = 0; i < vertexIndices.size(); i += 3)
    {

        unsigned int first = vertexIndices[i];
        unsigned int second = vertexIndices[i + 1];
        unsigned int third = vertexIndices[i + 2];
        ans.push_back(first - 1);
        ans.push_back(second - 1);
        ans.push_back(second - 1);
        ans.push_back(third - 1);
        ans.push_back(first - 1);
        ans.push_back(third - 1);
    }

    return ans;
}

std::vector<std::string> ObjReader::split(std::string s, std::string regexMatch)
{
    std::regex regex(regexMatch);

    std::vector<std::string> out(
        std::sregex_token_iterator(s.begin(), s.end(), regex, -1),
        std::sregex_token_iterator());
    return out;
}