#version 330
layout(location = 0) in vec3 position;
// TODO:  Add an input for texture coordinates
layout(location = 1) in vec2 textureCoords;

layout (location = 2) in vec3 normals;
layout (location = 3) in vec3 tangents;
layout (location = 4) in vec3 bitangents; 

// We now have our camera system set up.
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

// We define a new output vec2 for our texture coordinates.
out vec2 texCoords;

void main()
{
    // make TBN
    vec3 T = normalize(vec3(modelMatrix * vec4(tangents,   0.0)));
   vec3 B = normalize(vec3(modelMatrix * vec4(bitangents, 0.0)));
   vec3 N = normalize(vec3(modelMatrix * vec4(normals,    0.0)));
    mat3 TBN = mat3(T, B, N);


    // We have our transformed position set properly now
    gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1.0);
    // And we map our texture coordinates as appropriate
    texCoords = textureCoords;
}