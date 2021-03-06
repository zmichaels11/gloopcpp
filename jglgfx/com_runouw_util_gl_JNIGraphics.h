/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_runouw_util_gl_JNIGraphics */

#ifndef _Included_com_runouw_util_gl_JNIGraphics
#define _Included_com_runouw_util_gl_JNIGraphics
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxGetCurrentContext
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxGetCurrentContext
  (JNIEnv *, jclass);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDestroyContext
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDestroyContext
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxGetBlendMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxGetBlendMode
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxSetBlendMode
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxSetBlendMode
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxClear
 * Signature: (J[F)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxClear
  (JNIEnv *, jclass, jlong, jfloatArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxClearRect
 * Signature: (J[FIIII)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxClearRect
  (JNIEnv *, jclass, jlong, jfloatArray, jint, jint, jint, jint);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawLine
 * Signature: (J[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDrawLine
  (JNIEnv *, jclass, jlong, jfloatArray, jfloatArray, jfloatArray, jfloatArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawRect
 * Signature: (J[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDrawRect
  (JNIEnv *, jclass, jlong, jfloatArray, jfloatArray, jfloatArray, jfloatArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawTriangle
 * Signature: (J[F[F[F[F[F)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDrawTriangle
  (JNIEnv *, jclass, jlong, jfloatArray, jfloatArray, jfloatArray, jfloatArray, jfloatArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxFlush
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxFlush
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxCreateSpritesheet
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxCreateSpritesheet
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDestroySpritesheet
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDestroySpritesheet
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxSpritesheetAddInput
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxSpritesheetAddInput
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxSpritesheetRemoveInput
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxSpritesheetRemoveInput
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxInvalidateSpritesheet
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxInvalidateSpritesheet
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxGetSpritesheetImage
 * Signature: (J[I[I[I)J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxGetSpritesheetImage
  (JNIEnv *, jclass, jlong, jintArray, jintArray, jintArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    glgfxDrawSprite
 * Signature: (JJ[F[F)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_glgfxDrawSprite
  (JNIEnv *, jclass, jlong, jlong, jfloatArray, jfloatArray);

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    glgfxGetSpritesheetSprite
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_glgfxGetSpritesheetSprite
  (JNIEnv *, jclass, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
