KEYS = main_keys.c crypting_decrypting.c geting_value_from_keys.c files_reading_writing.c calculation.c
CRYPT = main_encryption.c geting_value_from_keys.c crypting_decrypting.c files_reading_writing.c calculation.c
DECRYPT = main_decryption.c geting_value_from_keys.c crypting_decrypting.c files_reading_writing.c calculation.c



one = key
two = crypt
tree = decrypt

${one} :
	gcc ${KEYS} -o keys ; ./keys
clean_key :
	rm -rf key_rsa key_rsa.pub keys
re_key : clean_key key

${two} :
	gcc ${CRYPT} -o crypt 
clean_crypt :
	rm -rf crypt
re_crypt : clean_crypt crypt

${tree} :
	gcc ${DECRYPT} -o decrypt  
clean_decrypt :
	rm -rf decrypt
re_decrypt : clean_decrypt decrypt

clean : clean_crypt clean_decrypt clean_key
