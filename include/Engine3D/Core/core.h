#pragma once
#include <cstdint>
#include <memory>

// Essentially to support Windows/Mac/Linux systems

// if we are on the Windows OS (since windows uses dll files)
#ifdef ENGING_PLATFORM_WINDOWS
    #ifdef ENGINE_BUILD_DLL
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else // If we are on either Linux/Mac OS, since they use __attributes__
    #define ENGINE_API __attribute__((visibility("default")))
#endif

#ifdef ENGINE_ENABLE_ASSERTS
	template<typename... T>
    void render_assert(bool x, T&&... args){
        if(!(x)){
            clientLogError("Assertion Failed: {}", std::forward(args)...);
            __debugbreak();
        }
    }

    template<typename... T>
    void render_core_assert(bool x, T&&... args){
        if(!(x)){
            coreLogError("Assertion Failed: {}", std::forward(args)...);
            __debugbreak();
        }
    }
#else
    template<typename... T>
    void render_assert(bool x, T&&... args){}

    template<typename... T>
    void render_core_assert(bool x, T&&... args){}
#endif

// @note Bitfields for multiple categories
constexpr uint64_t bit(uint64_t x){
	return (1 << x);
}

/*
 * @function bind_function
 * @note Template function allowing for creating functions objects that have a binding argument to a callable object
 * @note In this case the bindable argument is the instance pointer to the object we are calling the function to.
 *
 * @param instance 
 * @note Passing the instance for retrieving the callable function from that instance.
 *
 * @param function
 * @note when you pass a callable member function of the given instance that your passing to.
 *
 * @TODO Probably might want to have way of checking if the instance we are calling has a function that exists.
 *
 *
*/

static auto bind_function(auto* instance, auto function){
	return [instance, function](auto&& arg1){
		return (instance->*function)(std::forward<decltype(arg1)>(arg1));
	};
}

namespace Engine3D{
	/*
	 * @function CreateScope<T>
	 * @param T takes any type we want to be a std::unique_ptr
	 * @note Creating std::unique_ptr, the type we pass will only live lifetime of its declaration.
	 * */
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args&&... args){
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	/*
	 * @function CreateRef<T>
	 * @note type passed in to allow the object to live both inside other areas the objects being used. (lifetime)
	 *
	*/

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args&&... args){
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
};
