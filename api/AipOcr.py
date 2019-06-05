# -*- coding: utf-8 -*-

from aip import AipOcr  # pip3 install baidu-aip
import sys

inputPicPath = sys.argv[1]
outputTxtPath = sys.argv[2]


""" 读取图片 """
def get_file_content(filePath):
    with open(filePath, 'rb') as fp:
        return fp.read()

# 从文件中读取App id, api key, secret key
# 要求在key.txt中固定写入三行, 分别为App id, api key, secret key
def get_key():
	keys = []
	with open("key.txt", 'r') as f:
		print("open key file ok")
		keys = f.readlines()
		if len(keys) < 3:
			print("key len error")
			return keys
		APP_ID = keys[0].strip()
		API_KEY = keys[1].strip()
		SECRET_KEY = keys[2].strip()
		return keys
	print("open key file error")
	return keys

""" 你的 APPID AK SK """
keys = get_key()
APP_ID = keys[0]
API_KEY = keys[1]
SECRET_KEY = keys[2]

print(APP_ID)
print(API_KEY)
print(SECRET_KEY)

client = AipOcr(APP_ID, API_KEY, SECRET_KEY)


image = get_file_content(inputPicPath)
#options = {}
#options["language_type"] = "CHN_ENG"  # 识别语言类型，默认为CHN_ENG
#options["detect_direction"] = "false"  # 是否检测图像朝向，默认不检测，即：false。朝向是指输入图像是正常方向、逆时针旋转90/180/270度。
#options["detect_language"] = "false"  # 是否检测语言，默认不检测。当前支持（中文、英语、日语、韩语）
#options["probability"] = "false"

#text = client.basicGeneral(image, options)

text = client.basicAccurate(image)
#print(text)

#对文字进行保存
fp = open(outputTxtPath, 'w')

result = text['words_result']
for i in result:
    fp.writelines(i['words'] + "\n")

fp.close()
print('end')
