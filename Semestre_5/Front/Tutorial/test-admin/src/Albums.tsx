import {List,  Datagrid, TextField, ReferenceField, 
    EditButton, Edit, SimpleForm, TextInput, Create, EmailField, ReferenceInput}from "react-admin";


export const AlbumList= () =>(
    <List>
    <Datagrid>

        <ReferenceField source="userId" reference="users"/>
        <TextField source="id"/>
        <TextField source="title"/>
        <EditButton/>
        
        
    </Datagrid>
    </List>
    );

export const AlbumEdit= () =>(
    <Edit>
        <SimpleForm>
        <ReferenceField source="userId" reference="users"/>
        <TextField source="id" />
        <TextInput source="title"/>
        </SimpleForm>
    </Edit>
);

export const AlbumCreate= () =>(
    <Create>
        <SimpleForm>
        <ReferenceField source="userId" reference="users"/>
        <TextField source="id"/>
        <TextInput source="title"/>
        </SimpleForm>
    </Create>)