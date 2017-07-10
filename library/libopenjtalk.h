#ifndef LIB_OPENJTALK_H_
#define LIB_OPENJTALK_H_

#include "mecab.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "njd.h"
#include "jpcommon.h"
#include "HTS_engine.h"

#define MAXBUFLEN 1024

typedef struct _Open_JTalk {
    Mecab mecab;
    NJD njd;
    JPCommon jpcommon;
    HTS_Engine engine;
} Open_JTalk;


Open_JTalk* Open_JTalk_initialize();
void Open_JTalk_clear(Open_JTalk **);
int Open_JTalk_load(Open_JTalk * open_jtalk, char *dn_mecab, char *fn_voice);
int Open_JTalk_synthesis(Open_JTalk * open_jtalk, const char *txt,
    const char *wav_file_path, const char *log_file_path);
int Open_JTalk_synthesis_labels(Open_JTalk * open_jtalk, const char *txt,
    const char *wav_file_path,
    const char *text_anal_file_path,
    const char *context_label_file_path);

void Open_JTalk_set_sampling_frequency(Open_JTalk * open_jtalk, size_t i);
void Open_JTalk_set_fperiod(Open_JTalk * open_jtalk, size_t i);
void Open_JTalk_set_alpha(Open_JTalk * open_jtalk, double f);
void Open_JTalk_set_beta(Open_JTalk * open_jtalk, double f);
void Open_JTalk_set_speed(Open_JTalk * open_jtalk, double f);
void Open_JTalk_add_half_tone(Open_JTalk * open_jtalk, double f);
void Open_JTalk_set_msd_threshold(Open_JTalk * open_jtalk, size_t i, double f);
void Open_JTalk_set_gv_weight(Open_JTalk * open_jtalk, size_t i, double f);
void Open_JTalk_set_volume(Open_JTalk * open_jtalk, double f);
void Open_JTalk_set_audio_buff_size(Open_JTalk * open_jtalk, size_t i);

#ifdef __cplusplus
}
#endif

#endif  // LIB_OPENJTAKL_H_
