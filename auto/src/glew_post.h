/* ------------------------------------------------------------------------- */

/* error codes */
#define GLEW_OK 0
#define GLEW_ERROR_NO_GL_VERSION 1  /* missing GL version */
#define GLEW_ERROR_NO_EXTENSIONS_STRING 2  /* missing {ARB,EXT}_extensions_string */
#define GLEW_ERROR_GL_VERSION_10_ONLY 3  /* GL 1.1 and up are not supported */
#define GLEW_ERROR_GLX_VERSION_11_ONLY 4  /* GLX 1.2 and up are not supported */

/* API */
GLEWAPI GLboolean glewExperimental;
GLEWAPI GLuint glewInit ();
GLEWAPI GLboolean glewGetExtension (const char* name);
GLEWAPI const char* glewGetErrorString (GLuint error);

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

#undef GLAPI
/* #undef GLEWAPI */

#endif /* __glew_h__ */
