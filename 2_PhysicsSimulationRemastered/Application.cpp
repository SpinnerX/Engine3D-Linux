#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EntryPoint.h>

namespace Engine3DLinux{
    class SimulationApplication : public Application{
    public:
        SimulationApplication(ApplicationCommandLineArgs args) : Application("Physics Simulation", args) {

        }

        ~SimulationApplication(){}
    };

    Application* CreateApplication(ApplicationCommandLineArgs args){
        return new SimulationApplication(args);
    }
};