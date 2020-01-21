/** @file main.cpp
 *  @brief Entry point into our program.
 *  
 *  Welcome to the Great Looking Software Render 
 *  code base (Yes, I needed something with a gl prefix).
 *
 *  This is where you will implement your graphics API.
 *
 *  Compile on the terminal with: 
 *
 *  clang++ -std=c++11 main.cpp -o main
 *
 *  @author Mike Shah
 *  @bug No known bugs.
 */

// Load our libraries
#include <iostream>

// Some define values
#define WINDOW_HEIGHT 320
#define WINDOW_WIDTH 320

// C++ Standard Libraries
#include <iostream>

// Math Library
#include <algorithm> 

// User libraries
#include "GL.h"
#include "Color.h"
#include "TGA.h"
#include "Maths.h"

// Create a canvas to draw on.
TGA canvas(WINDOW_WIDTH,WINDOW_HEIGHT);


// Implementation of Bresenham's Line Algorithm
// The input to this algorithm is two points and a color
// This algorithm will then modify a canvas (i.e. image)
// filling in the appropriate colors.
void drawLine(Vec2 v0, Vec2 v1, TGA& image, ColorRGB c){
    bool steep = false;
    if(std::abs(v0.x-v1.x)<std::abs(v0.y-v1.y)){
        // If the line is steep we want to transpose the image.
        std::swap(v0.x,v0.y);
        std::swap(v1.x,v1.y);
        steep = true;
    }
    if(v0.x>v1.x){  // make it left-to-right
        std::swap(v0.x, v1.x);
        std::swap(v0.y, v1.y);
    }
    for(int x = v0.x; x <= v1.x; ++x){
        float t = (x-v0.x)/(float)(v1.x-v0.x);
        int y = v0.y*(1.0f-t) + v1.y*t;
        if(steep){
            canvas.setPixelColor(y,x,c);
        }else{
            canvas.setPixelColor(x,y,c);
        }
    }
}

float crossProduct(Vec2 v1, Vec2 v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

// fill triangle
void fillTriangle(Vec2 v0, Vec2 v1, Vec2 v2, TGA& image, ColorRGB c) {

    int maxX = std::max(v0.x, std::max(v1.x, v2.x));
    int minX = std::min(v0.x, std::min(v1.x, v2.x));
    int maxY = std::max(v0.y, std::max(v1.y, v2.y));
    int minY = std::min(v0.y, std::min(v1.y, v2.y));


    Vec2 vs1(v1.x - v0.x, v1.y - v0.y);
    Vec2 vs2(v2.x - v0.x, v2.y - v0.y);

    for (int x = minX; x <= maxX; x++)
        {
            for (int y = minY; y <= maxY; y++)
            {
                Vec2 q(x - v0.x, y - v0.y);

                float s = (float)crossProduct(q, vs2) / crossProduct(vs1, vs2);
                float t = (float)crossProduct(vs1, q) / crossProduct(vs1, vs2);

                if ( (s >= 0) && (t >= 0) && (s + t <= 1))
                    { /* inside triangle */
                    image.setPixelColor(x, y, c);
                    }
            }
        }

}

// Draw a triangle
void triangle(Vec2 v0, Vec2 v1, Vec2 v2,TGA& image, ColorRGB c){
    if(glFillMode==LINE){
        drawLine(v0,v1,image,c);
        drawLine(v1,v2,image,c);
        drawLine(v2,v0,image,c);
    }

    fillTriangle(v0, v1, v2, image, c);

}





// Main
int main(){

    // A sample of color(s) to play with
    ColorRGB red;
    red.r = 0; red.g = 0; red.b = 255;

    // Purple Color
    ColorRGB purple;
    purple.r = 221; purple.g = 160; purple.b = 221;

    // Sunrise Color
    ColorRGB sunrise;
    sunrise.r = 255; sunrise.g = 219; sunrise.b = 0;
        
    
    // Points for our Line
    Vec2 line[2] = {Vec2(0,0), Vec2(100,100)};

    // Set the fill mode
    glPolygonMode(FILL);

    // Draw a line
    drawLine(line[0],line[1],canvas,red);

    // Data for our triangle
    Vec2 tri[3] = {Vec2(160,60),Vec2(150,10),Vec2(75,190)};

    //Data for t2
    Vec2 tri2[3] = {Vec2(100,150),Vec2(200,300),Vec2(300,150)};;

    //Data for t3
    Vec2 tri3[3] = {Vec2(50,10),Vec2(50,60),Vec2(100,10)};;

    // Draw a triangle
    triangle(tri[0],tri[1],tri[2],canvas,red);

    triangle(tri2[0],tri2[1],tri2[2],canvas,purple);

    triangle(tri3[0],tri3[1],tri3[2],canvas,sunrise);


    // Output the final image
    canvas.outputTGAImage("graphics_lab2.ppm");

    return 0;
}
