#ifndef __RECORD_H__
#define __RECORD_H__

#include <inttypes.h>
#include "./app/Board_App/mp3_player/Backend_mp3Player.h"

/* RECBUFFER_SIZE����������������С��ʵ��ÿ��������ռ��RAM�ռ��ֽ���Ϊ��RECBUFFER_SIZE*2
 * ����ѡ��I2S_AudioFreq_16k������ʹ��RECBUFFER_SIZEΪ1024*4���Ϳɱ�֤¼��������Ч��������
 * ���ѡ���������߲�������Ҫ�ʵ�������RECBUFFER_SIZE��С�����統ѡ����I2S_AudioFreq_44k
 * ������RECBUFFER_SIZEΪ1024*8
 * ���⣬SD������Ķ�д�ٶ�Ҳ��һ��������Ӱ��¼��Ч��
 */
#define RECBUFFER_SIZE  1024*8

/* ¼���ļ����·�� */
#define RECORDERDIR	"0:/recorder"

void RecorderDemo(void);
void StartRecord(const char *filename);

#endif  /* __RECORD_H__   */

