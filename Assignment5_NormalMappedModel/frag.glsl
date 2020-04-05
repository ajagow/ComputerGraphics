#version 330

// Take in our texture coordinate from our vertex shader
in vec2 texCoords;

// And our normal
in vec3 norm;

// We always define a fragment color that we output.
out vec4 fragColor;

// And our fragment position for lighting
in vec3 fragPos;

uniform mat4 view;                  // we need the view matrix for highlights
uniform PointLight pointLights[1];

// Define our light(s)
struct PointLight {
    vec3 color;
    vec3 position;
    float ambientIntensity;
    float specularIntensity;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

// TODO:  Add a sampler to retrieve our color data from! done
uniform sampler2D textureSampler;

void main() {
  // Set our output fragment color to whatever we pull from our input texture (Note, change 'tex' to whatever the sampler is named)
  fragColor = texture(textureSampler, texCoords);
}