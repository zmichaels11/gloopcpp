namespace gloop {
	namespace wrapper {
		void bindBufferBase(unsigned int, unsigned int, unsigned int) {}
		void bindBufferRange(unsigned int, unsigned int, unsigned int, long, long) {}
		void getNamedBufferSubData(unsigned int, unsigned int, long, long, void *) {}
		void makeTextureHandleNonResident(unsigned long) {}
		void makeTextureHandleResident(unsigned long) {}
		unsigned long getTextureHandle(unsigned int) {}
		int getUniformBlockIndex(unsigned int, char const*) {}
	}
}
