/* ------------------------------------------------------------------------ */

#ifdef GLEW_MX

typedef struct GLXEWContextStruct GLXEWContext;
extern GLenum glxewContextInit (GLXEWContext* ctx);

#define GLXEW_GET_VAR(x) glxewGetContext()->x
#define GLXEW_GET_FUN(x) x

#else /* GLEW_MX */

#define GLXEW_GET_VAR(x) x
#define GLXEW_GET_FUN(x) x

#endif /* GLEW_MX */

extern GLboolean glxewGetExtension (const char* name);

#ifdef __cplusplus
}
#endif

#endif /* __glxew_h__ */
