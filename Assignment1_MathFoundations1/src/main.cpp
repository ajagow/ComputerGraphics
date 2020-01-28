// Includes for the assignment
#include "Vector4f.h"
#include "Matrix4f.h"
#include <iostream>

// Tests for comparing our library
// You may compare your operations against the glm library
// which is a well tested library.
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Sample unit test comparing against GLM.
bool unitTest0(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Matrix4f myIdentity( 1.0f,0,0,0,
        			     0,1.0f,0,0,
		        	     0,0,1.0f,0,
			             0,0,0,1.0f);

    if(
        glmIdentityMatrix[0][0]==myIdentity[0][0] &&
        glmIdentityMatrix[0][1]==myIdentity[0][1] &&
        glmIdentityMatrix[0][2]==myIdentity[0][2] &&
        glmIdentityMatrix[0][3]==myIdentity[0][3] &&
        glmIdentityMatrix[1][0]==myIdentity[1][0] &&
        glmIdentityMatrix[1][1]==myIdentity[1][1] &&
        glmIdentityMatrix[1][2]==myIdentity[1][2] &&
        glmIdentityMatrix[1][3]==myIdentity[1][3] &&
        glmIdentityMatrix[2][0]==myIdentity[2][0] &&
        glmIdentityMatrix[2][1]==myIdentity[2][1] &&
        glmIdentityMatrix[2][2]==myIdentity[2][2] &&
        glmIdentityMatrix[2][3]==myIdentity[2][3] &&
        glmIdentityMatrix[3][0]==myIdentity[3][0] &&
        glmIdentityMatrix[3][1]==myIdentity[3][1] &&
        glmIdentityMatrix[3][2]==myIdentity[3][2] &&
        glmIdentityMatrix[3][3]==myIdentity[3][3]){
            return true;
    }
	
    return false;	
}

bool unitTest1(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Matrix4f myIdentity( 1.0f,0,0,0,
        			     0,1.0f,0,0,
		        	     0,0,1.0f,0,
			             0,0,0,1.0f);

    if(
        glmIdentityMatrix[0][0]==myIdentity(0,0) &&
        glmIdentityMatrix[0][1]==myIdentity(0,1) &&
        glmIdentityMatrix[0][2]==myIdentity(0,2) &&
        glmIdentityMatrix[0][3]==myIdentity(0,3) &&
        glmIdentityMatrix[1][0]==myIdentity(1,0) &&
        glmIdentityMatrix[1][1]==myIdentity(1,1) &&
        glmIdentityMatrix[1][2]==myIdentity(1,2) &&
        glmIdentityMatrix[1][3]==myIdentity(1,3) &&
        glmIdentityMatrix[2][0]==myIdentity(2,0) &&
        glmIdentityMatrix[2][1]==myIdentity(2,1) &&
        glmIdentityMatrix[2][2]==myIdentity(2,2) &&
        glmIdentityMatrix[2][3]==myIdentity(2,3) &&
        glmIdentityMatrix[3][0]==myIdentity(3,0) &&
        glmIdentityMatrix[3][1]==myIdentity(3,1) &&
        glmIdentityMatrix[3][2]==myIdentity(3,2) &&
        glmIdentityMatrix[3][3]==myIdentity(3,3)){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
bool unitTest2(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Vector4f a(1.0f ,0.0f,  0.0f,   0.0f);
	Vector4f b(0.0f ,1.0f,  0.0f,   0.0f);
	Vector4f c(0.0f ,0.0f,  1.0f,   0.0f);
	Vector4f d(0.0f ,0.0f,  0.0f,   1.0f);
	Matrix4f myIdentity(a,b,c,d);

    if(
        glmIdentityMatrix[0][0]==myIdentity[0][0] &&
        glmIdentityMatrix[0][1]==myIdentity[0][1] &&
        glmIdentityMatrix[0][2]==myIdentity[0][2] &&
        glmIdentityMatrix[0][3]==myIdentity[0][3] &&
        glmIdentityMatrix[1][0]==myIdentity[1][0] &&
        glmIdentityMatrix[1][1]==myIdentity[1][1] &&
        glmIdentityMatrix[1][2]==myIdentity[1][2] &&
        glmIdentityMatrix[1][3]==myIdentity[1][3] &&
        glmIdentityMatrix[2][0]==myIdentity[2][0] &&
        glmIdentityMatrix[2][1]==myIdentity[2][1] &&
        glmIdentityMatrix[2][2]==myIdentity[2][2] &&
        glmIdentityMatrix[2][3]==myIdentity[2][3] &&
        glmIdentityMatrix[3][0]==myIdentity[3][0] &&
        glmIdentityMatrix[3][1]==myIdentity[3][1] &&
        glmIdentityMatrix[3][2]==myIdentity[3][2] &&
        glmIdentityMatrix[3][3]==myIdentity[3][3]){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
// TODO: Test against glm::scale
bool unitTest3(){
	glm::mat4 glmScale = glm::mat4(2.0f);
	Vector4f a(1.0f,0,0,0);
	Vector4f b(0.0f,1.0f,0,0);
	Vector4f c(0,0,1.0f,0);
	Vector4f d(0,0,0,1.0f);
	Matrix4f myScaled(a,b,c,d);
    myScaled.MakeScale(2.0f,2.0f,2.0f);

    if(
        glmScale[0][0]==myScaled[0][0] &&
        glmScale[0][1]==myScaled[0][1] &&
        glmScale[0][2]==myScaled[0][2] &&
        glmScale[0][3]==myScaled[0][3] &&
        glmScale[1][0]==myScaled[1][0] &&
        glmScale[1][1]==myScaled[1][1] &&
        glmScale[1][2]==myScaled[1][2] &&
        glmScale[1][3]==myScaled[1][3] &&
        glmScale[2][0]==myScaled[2][0] &&
        glmScale[2][1]==myScaled[2][1] &&
        glmScale[2][2]==myScaled[2][2] &&
        glmScale[2][3]==myScaled[2][3] &&
        glmScale[3][0]==myScaled[3][0] &&
        glmScale[3][1]==myScaled[3][1] &&
        glmScale[3][2]==myScaled[3][2] &&
        glmScale[3][3]==myScaled[3][3]){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
// Testing operator
bool unitTest4(){
	glm::mat4 glmTest = glm::mat4(1.0f);
    glmTest[1][3] = 72.0f;
    glmTest[2][3] = 2.1f;

	Matrix4f myMatrix(0,0,0,0,
                      0,0,0,0,
                      0,0,0,0,
                      0,0,0,0);

    myMatrix[1][3] = 72.0f;
    myMatrix[2][3] = 2.1f;

    if( glmTest[1][3]==myMatrix[1][3] &&
        glmTest[2][3]==myMatrix[2][3] ){
            return true;
    }
	
    return false;	
}

// Sample unit test testing your library
bool unitTest5(){
  Vector4f a(1,1,1,1);
  Vector4f b(0,0,0,0);
  Vector4f c = a + b;

  if(c.x == 1 && c.y == 1 && c.z ==1 && c.w==1){
    return true;
  }
    return false;
}

// Sample tests for vector4
bool unitTest6() {
    Vector4f a(1, 2, 3, 4);

    if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4) {
        return true;
    }

    return false;

}

bool unitTest7() {
    Vector4f a(1, 2, 3, 4);
    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);

    a *=(2.0f);
    aGLM *=(2.0f);

    if (aGLM[0] == a[0] && aGLM[1] == a[1] && aGLM[2] == a[2] && aGLM[3] == a[3]) {
        return true;
    }

    return false;

}

bool unitTest8() {
    Vector4f a(1, 2, 3, 4);
    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);

    a /=(2.0f);
    aGLM /=(2.0f);

    if (aGLM[0] == a[0] && aGLM[1] == a[1] && aGLM[2] == a[2] && aGLM[3] == a[3]) {
        return true;
    }

    return false;

}

bool unitTest9() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    a +=(b);
    aGLM +=(bGLM);


    if (aGLM[0] == a[0] && aGLM[1] == a[1] && aGLM[2] == a[2] && aGLM[3] == a[3]) {
        return true;
    }

    return false;

}

bool unitTest10() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    b -=(a);
    bGLM -=(aGLM);


    if (aGLM[0] == a[0] && aGLM[1] == a[1] && aGLM[2] == a[2] && aGLM[3] == a[3]) {
        return true;
    }

    return false;

}

bool unitTest11() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    float result1 = Dot(a, b);
    float result2 = glm::dot(aGLM, bGLM);

    if (result1 == result2) {
        return true;
    }

    return false;

}

bool unitTest12() {
    Vector4f a(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(9, 2.5, 3.99, 10);


    Vector4f result1 = a * 3.0f;
    glm::vec4 result2 = aGLM * 3.0f;

    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
        return true;
    }
    
    return false;

}

bool unitTest13() {
    Vector4f a(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(9, 2.5, 3.99, 10);


    Vector4f result1 = a / 3.0f;
    glm::vec4 result2 = aGLM / 3.0f;

    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
        return true;
    }
    
    return false;

}

bool unitTest14() {
    Vector4f a(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(9, 2.5, 3.99, 10);


    Vector4f result1 = -a;
    glm::vec4 result2 = -aGLM;

    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3] &&
    -9.0f == result1[0] && -2.5f == result1[1] && -3.99f == result1[2] && -10.0f == result1[3]) {
        return true;
    }

            
    return false;

}

bool unitTest15() {
    Vector4f a(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(9, 2.5, 3.99, 10);


    float result1 = Magnitude(a);
    float result2 = glm::length(aGLM);

    if (result1 == result2) {
        return true;
    }
     
    return false;

}

bool unitTest16() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    Vector4f result1 = a + b;
    glm::vec4 result2 = aGLM + bGLM;


    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
        return true;
    }

    return false;

}

bool unitTest17() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    Vector4f result1 = a - b;
    glm::vec4 result2 = aGLM - bGLM;


    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
        return true;
    }

    return false;

}

// TODO:  come back and fix me
bool unitTest18() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(1, 2, 3, 4);
    glm::vec4 bGLM = glm::vec4(9, 2.5, 3.99, 10);

    Vector4f result1 = Project(a, b);
    // glm::vec4 result2 = glm::projection(aGLM, bGLM);


    // if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
    //     return true;
    // }

    return false;

}

bool unitTest19() {
    Vector4f a(9, 2.5, 3.99, 10);

    glm::vec4 aGLM = glm::vec4(9, 2.5, 3.99, 10);

    Vector4f result1 = Normalize(a);
    glm::vec4 result2 = glm::normalize(aGLM);

    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2] && result2[3] == result1[3]) {
        return true;
    }


    return false;

}

bool unitTest20() {
    Vector4f a(1, 2, 3, 4);
    Vector4f b(9, 2.5, 3.99, 10);

    glm::vec3 aGLM = glm::vec3(1, 2, 3);
    glm::vec3 bGLM = glm::vec3(9, 2.5, 3.99);

    Vector4f result1 = CrossProduct(a, b);
    glm::vec3 result2 = glm::cross(aGLM, bGLM);

    if (result2[0] == result1[0] && result2[1] == result1[1] && result2[2] == result1[2]) {
        return true;
    }

    return false;

}



int main(){
    // Keep track of the tests passed
    unsigned int testsPassed = 0;

    // true = 1, false = 0

    // Run 'unit tests'
    // std::cout << "Passed 0: " << unitTest0() << " \n";
    // std::cout << "Passed 1: " << unitTest1() << " \n";
    // std::cout << "Passed 2: " << unitTest2() << " \n";
    // std::cout << "Passed 3: " << unitTest3() << " \n";
    // std::cout << "Passed 4: " << unitTest4() << " \n";
    // std::cout << "Passed 5: " << unitTest5() << " \n";
    std::cout << "Passed 6: " << unitTest6() << " \n";
    std::cout << "Passed 7: " << unitTest7() << " \n";
    std::cout << "Passed 8: " << unitTest8() << " \n";
    std::cout << "Passed 9: " << unitTest9() << " \n";
    std::cout << "Passed 10: " << unitTest10() << " \n";
    std::cout << "Passed 11: " << unitTest11() << " \n";
    std::cout << "Passed 12: " << unitTest12() << " \n";
    std::cout << "Passed 13: " << unitTest13() << " \n";
    std::cout << "Passed 14: " << unitTest14() << " \n";
    std::cout << "Passed 15: " << unitTest15() << " \n";
    std::cout << "Passed 16: " << unitTest16() << " \n";
    std::cout << "Passed 17: " << unitTest17() << " \n";
    // std::cout << "Passed 18: " << unitTest18() << " \n";
    std::cout << "Passed 19: " << unitTest19() << " \n";
    std::cout << "Passed 20: " << unitTest20() << " \n";



    return 0;
}
