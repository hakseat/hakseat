# Generated by Django 4.2.3 on 2023-08-02 15:33

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('content', '0005_delete_reply'),
    ]

    operations = [
        migrations.DeleteModel(
            name='Bookmark',
        ),
        migrations.DeleteModel(
            name='Like',
        ),
    ]
