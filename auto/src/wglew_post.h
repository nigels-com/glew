/* ------------------------------------------------------------------------- */

typedef struct WGLEWContextStruct WGLEWContext;
GLEWAPI WGLEWContext* wglewDefaultContext;

#ifdef GLEW_MX
extern WGLEWContext* wglewGetContext();
#  define WGLEW_GET_CONTEXT(x) wglewGetContext()->x
#else
#  define WGLEW_GET_CONTEXT(x) wglewDefaultContext->x
#endif /* GLEW_MX */

GLEWAPI GLenum wglewContextInit (WGLEWContext* ctx);
GLEWAPI GLboolean wglewGetExtension (const char* name);

#ifdef __cplusplus
}
#endif

/* #undef WGLEW_GET_CONTEXT */
#undef GLEWAPI

#endif /* __wglew_h__ */
