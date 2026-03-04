#pragma once
#include "GLContextEGL.h"
#include <span>

class GLContextEGLAndroid final : public GLContextEGL
{
public:
    GLContextEGLAndroid(const WindowInfo& wi);
    ~GLContextEGLAndroid() override;

    template<size_t N>
    static std::unique_ptr<GLContext> Create(
            const WindowInfo& wi,
            const GLContext::Version (&versions_to_try)[N],
            Error* error = nullptr
    ) {
        return Create(wi, versions_to_try, N, error);
    }

    std::unique_ptr<GLContext> CreateSharedContext(const WindowInfo& wi, Error* error) override;
    void ResizeSurface(u32 new_surface_width = 0, u32 new_surface_height = 0) override;
private:
    static std::unique_ptr<GLContext> Create(
            const WindowInfo& wi,
            const GLContext::Version* versions_to_try,
            size_t num_versions_to_try,
            Error* error
    );
protected:
    EGLNativeWindowType GetNativeWindow(EGLConfig config) override;
};
