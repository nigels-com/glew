/* ------------------------------------------------------------------------- */

/* error codes */
#define GLEW_OK 0
#define GLEW_NO_ERROR 0
#define GLEW_ERROR_NO_GL_VERSION 1  /* missing GL version */
#define GLEW_ERROR_GL_VERSION_10_ONLY 2  /* GL 1.1 and up are not supported */
#define GLEW_ERROR_GLX_VERSION_11_ONLY 3  /* GLX 1.2 and up are not supported */

/* string codes */
#define GLEW_VERSION 1

/* API */
#ifdef GLEW_MX
#  define GLEW_GET_CONTEXT(x) glewGetContext()->##x
#else
#  define GLEW_GET_CONTEXT(x) glewDefaultContext->##x
#endif /* GLEW_MX */

typedef struct GLEWContextStruct GLEWContext;

GLEWAPI GLEWContext* glewDefaultContext;
GLEWAPI GLboolean glewExperimental;

GLEWAPI GLenum glewInit ();
GLEWAPI GLenum glewContextInit (GLEWContext* ctx);

GLEWAPI GLboolean glewGetExtension (const GLubyte* name);
GLEWAPI const GLubyte* glewGetErrorString (GLenum error);
GLEWAPI const GLubyte* glewGetString (GLenum name);

#ifdef __cplusplus
}
#endif

#ifdef GLEW_APIENTRY_DEFINED
#undef GLEW_APIENTRY_DEFINED
#undef APIENTRY
#undef GLAPIENTRY
#endif

#ifdef GLEW_CALLBACK_DEFINED
#undef GLEW_CALLBACK_DEFINED
#undef CALLBACK
#endif

#ifdef GLEW_WINGDIAPI_DEFINED
#undef GLEW_WINGDIAPI_DEFINED
#undef WINGDIAPI
#endif

/* #undef GLEW_GET_CONTEXT */
#undef GLAPI
/* #undef GLEWAPI */

#endif /* __glew_h__ */
