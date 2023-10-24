#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <cstdint>

// Include your loadPPM function and the Image and Pixel structures
struct Pixel {
    uint8_t r, g, b;
};

struct Image {
    int width, height;
    std::vector<Pixel> data;
};

Image loadPPM(const std::string &filename);

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1024, 1024, "PPM Viewer", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load PPM image data
    Image img = loadPPM("..\\test_files\\ppm\\coloful.ppm");

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRasterPos2i((width - img.width) / 2, (height - img.height) / 2); // Center the image
        glPixelZoom(1.0, -1.0); // Flip vertically as OpenGL's origin is bottom-left
        glDrawPixels(img.width, img.height, GL_RGB, GL_UNSIGNED_BYTE, img.data.data());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
