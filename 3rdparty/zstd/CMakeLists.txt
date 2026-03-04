enable_language(C ASM)

add_library(pcsx2-zstd
	lib/common/debug.c
	lib/common/entropy_common.c
	lib/common/error_private.c
	lib/common/fse_decompress.c
	lib/common/pool.c
	lib/common/threading.c
	lib/common/xxhash.c
	lib/common/zstd_common.c
	lib/compress/fse_compress.c
	lib/compress/hist.c
	lib/compress/huf_compress.c
	lib/compress/zstd_compress.c
	lib/compress/zstd_compress_literals.c
	lib/compress/zstd_compress_sequences.c
	lib/compress/zstd_compress_superblock.c
	lib/compress/zstd_double_fast.c
	lib/compress/zstd_fast.c
	lib/compress/zstd_lazy.c
	lib/compress/zstd_ldm.c
	lib/compress/zstdmt_compress.c
	lib/compress/zstd_opt.c
	lib/decompress/huf_decompress.c
	lib/decompress/zstd_ddict.c
	lib/decompress/zstd_decompress_block.c
	lib/decompress/zstd_decompress.c
)

if(_M_X86 AND (NOT MSVC OR USE_CLANG_CL))
	target_sources(pcsx2-zstd PRIVATE lib/decompress/huf_decompress_amd64.S)
endif()

target_include_directories(pcsx2-zstd PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib")

add_library(Zstd::Zstd ALIAS pcsx2-zstd)