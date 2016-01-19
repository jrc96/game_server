﻿/*
 * GameToLog.h
 *
 *  Created on: 2015年12月23日
 *      Author: zhangyalei
 */

#ifndef MSG_GAMETOLOG_H_
#define MSG_GAMETOLOG_H_

#include <cstring>
#include "Block_Buffer.h"

/*
记录日志文件
*/
struct MSG_180000 {
	uint8_t log_type;/*日志类型*/
	uint8_t log_sub_type;/**/
	int32_t pid;/*进程id*/
	int64_t tid;/*线程id*/
	uint32_t time;/**/
	std::string log_str;/**/

	MSG_180000(void);
	void serialize(Block_Buffer& w) const;
	int deserialize(Block_Buffer& r);
	void reset(void);
};

/*
记录buffer日志
*/
struct MSG_180001 {
	uint8_t log_type;/*日志类型*/
	uint8_t log_sub_type;/**/
	int64_t role_id;/*角色id*/
	std::string file_name;/**/
	std::string buf;/**/

	MSG_180001(void);
	void serialize(Block_Buffer& w) const ;
	int deserialize(Block_Buffer& r);
	void reset(void);
};

/*
后台MySQL数据库插入测试
*/
struct MSG_185000 {
	int32_t id;
	std::string name;

	MSG_185000(void);
	void serialize(Block_Buffer& w) const;
	int deserialize(Block_Buffer& r);
	void reset(void);
};

/*
后台登录退出流水
*/
struct MSG_185001 {
	int64_t role_id;/*角色id*/
	std::string role_name;/*角色名*/
	std::string account;/*账号*/
	uint16_t level;/*等级*/
	std::string client_ip;/*客户端IP*/
	uint32_t login_time;/*登录时间戳*/
	uint32_t logout_time;/*退出时间戳*/
	uint32_t online_time;/*在线时长*/

	MSG_185001(void);
	void serialize(Block_Buffer& w) const;
	int deserialize(Block_Buffer& r);
	void reset(void);
};

#endif /* MSG_GAMETOLOG_H_ */