/* ------------------------------------------------------------------------ */

typedef struct GLXEWContextStruct GLXEWContext;
GLEWAPI GLXEWContext* glxewDefaultContext;

#ifdef GLEW_MX
extern GLXEWContext* glxewGetContext();
#  define GLXEW_GET_CONTEXT(x) glxewGetContext()->x
#else
#  define GLXEW_GET_CONTEXT(x) glxewDefaultContext->x
#endif /* GLEW_MX */

extern GLenum glxewContextInit (GLXEWContext* ctx);
extern GLboolean glxewGetExtension (const GLubyte* name);

#ifdef __cplusplus
}
#endif

#endif /* __glxew_h__ */
