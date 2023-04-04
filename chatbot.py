import openai

openai.api_key = "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"

response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    messages=[
            {"role": "user", "content": "Que medidas de seguridad se pueden tomar ante un objeto cercano desconocido al Sensor Ultrasónico?"},
        ]
)

result = ''
for choice in response.choices:
    result += choice.message.content
print(result)