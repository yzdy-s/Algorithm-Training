import os
from openai import OpenAI

# 从环境变量中获取您的API KEY，配置方法见：https://www.volcengine.com/docs/82379/1399008
api_key = "ark-41cd6564-1942-4f72-b8da-432f7df7eac3-e14bf"

client = OpenAI(
    base_url="https://ark.cn-beijing.volces.com/api/v3",
    api_key=api_key,
)

response = client.responses.create(
    model="doubao-seed-1-8-251228",
    input=[
        {
            "role": "user",
            "content": [

                {
                    "type": "input_image",
                    "image_url": "https://ark-project.tos-cn-beijing.volces.com/doc_image/ark_demo_img_1.png"
                },
                {
                    "type": "input_text",
                    "text": "你看见了什么？"
                },
            ],
        }
    ]
)

print(response)