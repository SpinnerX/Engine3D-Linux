#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Core/EntryPoint.h>
#include "SimulationLayer.h"

namespace Engine3DLinux{
    class SimulationApplication : public Application{
    public:
        SimulationApplication(ApplicationCommandLineArgs args) : Application("Physics Simulation", args) {
            pushLayer(new SimulationLayer());
        }

        ~SimulationApplication() {}
    };

    Application* CreateApplication(ApplicationCommandLineArgs args){
		return new SimulationApplication(args);
	}
};