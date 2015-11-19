/* ------------------------------------------------------------------------ */

GLEWAPI GLenum GLEWAPIENTRY glxewInit ();
GLEWAPI GLboolean GLEWAPIENTRY glxewIsSupported (const char *name);

#define GLXEW_GET_VAR(x) (*(const GLboolean*)&x)
#define GLXEW_GET_FUN(x) x

GLEWAPI GLboolean GLEWAPIENTRY glxewGetExtension (const char *name);

#ifdef __cplusplus
}
#endif

#endif /* __glxew_h__ */
