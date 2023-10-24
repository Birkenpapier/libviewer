#include <iostream>
#include <vector>
#include <fstream>

struct Pixel {
    uint8_t r, g, b;
};

struct Image {
    int width, height;
    std::vector<Pixel> data;
};

Image loadPPM(const std::string &filename) {
    Image img;
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file" << std::endl;
        return img;
    }

    std::string header;
    file >> header;
    if (header != "P3") {
        std::cerr << "Unsupported PPM format" << std::endl;
        return img;
    }

    file >> img.width >> img.height;
    int maxVal;
    file >> maxVal;

    img.data.resize(img.width * img.height);
    for (int i = 0; i < img.width * img.height; ++i) {
        int r, g, b;
        file >> r >> g >> b;
        img.data[i] = {static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b)};
    }

    return img;
}
