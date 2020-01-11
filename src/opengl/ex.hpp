#ifndef APYTUU_ENGINE_OPENGL_EX
#define APYTUU_ENGINE_OPENGL_EX
namespace apytuu_engine_opengl{
	class OpenGLException{
	public:
		OpenGLException(const char *msg) : msg(msg) {}
		const char* msg;
	};
}
#endif
