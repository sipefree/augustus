#ifndef ASSETS_XML_H
#define ASSETS_XML_H

// Do not change the seed. Doing so breaks savegame compatibility with extra asset images
#define HASH_SEED 0x12345678
#define XML_STRING_MAX_LENGTH 32

#define XML_BUFFER_SIZE 1024
#define XML_MAX_DEPTH 4
#define XML_MAX_ELEMENTS_PER_DEPTH 4
#define XML_MAX_ATTRIBUTES 9
#define XML_TAG_MAX_LENGTH 24
#define XML_MAX_IMAGE_INDEXES 256

void xml_process_assetlist_file(const char *xml_file_name);
void xml_get_full_image_path(char *full_path, const char *image_file_name);

#endif // ASSETS_XML_H
