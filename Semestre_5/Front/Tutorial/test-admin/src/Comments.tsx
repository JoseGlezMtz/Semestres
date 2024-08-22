import {List,  Datagrid, TextField, ReferenceField, 
    EditButton, Edit, SimpleForm, TextInput, Create, EmailField, ReferenceInput}from "react-admin";


export const CommentsList= () =>(
    <List>
    <Datagrid>

        <ReferenceField source="postId" reference="posts"/>
        <TextField source="id"/>
        <TextField source="name"/>
        <EmailField source="email"/>
        <TextField source="body"/>
        <EditButton/>
        
        
    </Datagrid>
    </List>
    );

export const CommentsEdit= () =>(
    <Edit>
        <SimpleForm>
            <ReferenceField source="postId" reference="posts"  />
            <TextInput source="id" InputProps = {{disabled: true}}/>
            <TextField source="name"/>
            <TextInput source="email" InputProps = {{disabled: true}}/>
            <TextInput source="body"/>
        </SimpleForm>
    </Edit>
);

export const CommentsCreate= () =>(
    <Create>
        <SimpleForm>
        <ReferenceInput source="postId" reference="posts"/>
        <TextInput source="name"/>
        <TextInput source="email"/>
        <TextInput source="body" multiline rows={5}/>
        </SimpleForm>
    </Create>)