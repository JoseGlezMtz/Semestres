import {List,  Datagrid, TextField, ReferenceField, 
    EditButton, Edit, SimpleForm, TextInput, Create, EmailField, ReferenceInput, ImageField}from "react-admin";


export const PhotoList= () =>(
    <List>
    <Datagrid>

        <ReferenceField source="albumId" reference="albums"/>
        <TextField source="id"/>
        <TextField source="title"/>
        <ImageField source="url"/>
        <ImageField source="thumbnailUrl"/>
        <EditButton/>
        
        
    </Datagrid>
    </List>
    );

export const PhotoEdit= () =>(
    <Edit>
        <SimpleForm>
        <ReferenceField source="albumId" reference="albums"/>
        <TextInput source="id" InputProps = {{disabled: true}}/>
        <TextInput source="title"/>
        <TextInput source="url"/>
        <TextInput source="thumbnailUrl"/>
        </SimpleForm>
    </Edit>
);

export const PhotoCreate= () =>(
    <Create>
        <SimpleForm>
        <ReferenceField source="albumId" reference="albums"/>
        <TextInput source="id"/>
        <TextInput source="title"/>
        <TextInput source="url"/>
        <TextInput source="thumbnailUrl"/>
        </SimpleForm>
    </Create>)