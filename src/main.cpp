#include "Scene.h"


const char* static_background_scene =
"................................................................\n"
"|                                                              |\n"
"|                                                              |\n"
"|                                                              |\n"
"|                                                              |\n"
"|                                                              |\n"
"|                  @                                           |\n"
"................................................................\n";

int main(){
    Scene scene(static_background_scene);
    scene.print();
    return 0;
};
