#include <iostream>
#include <fstream>
#include "../Model/VM.h"
#include "../View/EditorView.h"
#include "../View/BarView.h"
#include "../Controller/VmKeyboard.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Usage: vm filename\n";
    } else {
        VM vm{};
        std::string bufferName {argv[1]};
        vm.setBuffer(bufferName);
        vm.addView(std::make_unique<EditorView>(&vm));
        vm.addView(std::make_unique<BarView>(&vm));
        vm.addController(std::make_unique<VmKeyboard>(&vm));
        vm.mainLoop();
        return 0;
    }
}
