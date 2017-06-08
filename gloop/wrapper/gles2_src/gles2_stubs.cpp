namespace gloop {
	namespace wrapper {
		void bindBufferBase(unsigned int, unsigned int, unsigned int) {
			__builtin_trap(); 
		}

		void bindBufferRange(unsigned int, unsigned int, unsigned int, long, long) {
			__builtin_trap();
		}

		void getNamedBufferSubData(unsigned int, unsigned int, long, long, void *) {
			__builtin_trap();
		}

		void makeTextureHandleNonResident(unsigned long) {
			__builtin_trap();
		}

		void makeTextureHandleResident(unsigned long) {
			__builtin_trap();
		}

		unsigned long getTextureHandle(unsigned int) {
			__builtin_trap();
			return 0;
		}

		int getUniformBlockIndex(unsigned int, char const*) {
			__builtin_trap();
			return 0;
		}
	}
}
