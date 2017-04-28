/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "com_runouw_util_gl_JNIGraphics.h"

#include <stdint.h>

#include "../cglgfx/graphics.h"

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxGetCurrentContext
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxGetCurrentContext
  (JNIEnv *, jclass) {
    
    return (jlong) (intptr_t) glgfxGetCurrentContext();
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDestroyContext
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDestroyContext
  (JNIEnv *, jclass, jlong ctx) {
    
    glgfxDestroyContext((void *) (intptr_t) (ctx));
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxGetBlendMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxGetBlendMode
  (JNIEnv *, jclass, jlong ctx) {
    
    return (jint) glgfxGetBlendMode((void *) (intptr_t) ctx);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxSetBlendMode
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxSetBlendMode
  (JNIEnv *, jclass, jlong ctx, jint blend) {
    
    glgfxSetBlendMode((void *) (intptr_t) ctx, (uint32_t) blend);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxClear
 * Signature: (J[F)V
 */
JNIEXPORT void JNICALL JavaCritical_com_runouw_util_gl_JNIGraphics_jglgfxClear
  (JNIEnv *, jclass, jlong ctx, jfloat* color) {        
    
    glgfxClear((void *) (intptr_t) ctx, (float *) color);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxClearRect
 * Signature: (J[FIIII)V
 */
JNIEXPORT void JNICALL JavaCritical_com_runouw_util_gl_JNIGraphics_jglgfxClearRect
  (JNIEnv *, jclass, jlong ctx, jfloat * color, jint x, jint y, jint width, jint height) {
    
    glgfxClearRect((void *) (intptr_t) ctx, (float *) color, (int32_t) x, (int32_t) y, (uint32_t) width, (uint32_t) height);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawLine
 * Signature: (J[F[F[F[F)V
 */
JNIEXPORT void JNICALL JavaCritical_com_runouw_util_gl_JNIGraphics_jglgfxDrawLine
  (JNIEnv *, jclass, jlong ctx, jfloat * mvp, jfloat * color, jfloat * p0, jfloat * p1) {
    
    glgfxDrawLine((void *) (intptr_t) ctx, (float *) mvp, (float *) color, (float *) p0, (float *) p1);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawRect
 * Signature: (J[F[F[F[F)V
 */
JNIEXPORT void JNICALL JavaCritical_com_runouw_util_gl_JNIGraphics_jglgfxDrawRect
  (JNIEnv *, jclass, jlong ctx, jfloat * mvp, jfloat * color, jfloat * pos, jfloat * size) {
    
    glgfxDrawRect((void *) (intptr_t) ctx, (float *) mvp, (float *) color, (float *) pos, (float *) size);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDrawTriangle
 * Signature: (J[F[F[F[F[F)V
 */
JNIEXPORT void JNICALL JavaCritical_com_runouw_util_gl_JNIGraphics_jglgfxDrawTriangle
  (JNIEnv *, jclass, jlong ctx, jfloat * mvp, jfloat * color, jfloat * p0, jfloat * p1, jfloat * p2) {
    
    glgfxDrawTriangle((void *) (intptr_t) ctx, (float *) mvp, (float *) color, (float *) p0, (float *) p1, (float *) p2);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxFlush
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxFlush
  (JNIEnv *, jclass, jlong ctx) {
    
    glgfxFlush((void * ) (intptr_t) ctx);
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxCreateSpritesheet
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxCreateSpritesheet
  (JNIEnv *, jclass, jstring name) {
    
}

/*
 * Class:     com_runouw_util_gl_JNIGraphics
 * Method:    jglgfxDestroySpritesheet
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_runouw_util_gl_JNIGraphics_jglgfxDestroySpritesheet
  (JNIEnv *, jclass, jlong spriteSheet) {
    
    glgfxDestroySpritesheet((void *) (intptr_t) spriteSheet);
}

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