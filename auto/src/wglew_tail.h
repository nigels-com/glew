/* ------------------------------------------------------------------------- */

#ifdef GLEW_MX

typedef struct WGLEWContextStruct WGLEWContext;
GLEWAPI GLenum wglewContextInit (WGLEWContext* ctx);

#define WGLEW_GET_VAR(x) wglewGetContext()->x
#define WGLEW_GET_FUN(x) wglewGetContext()->x

#else /* GLEW_MX */

#define WGLEW_GET_VAR(x) x
#define WGLEW_GET_FUN(x) x

#endif /* GLEW_MX */

GLEWAPI GLboolean wglewGetExtension (const char* name);

#ifdef __cplusplus
}
#endif

#undef GLEWAPI

#endif /* __wglew_h__ */
