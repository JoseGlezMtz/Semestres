
import {
  Admin,
  Resource,
  ListGuesser,
  EditGuesser,
  ShowGuesser,
} from "react-admin";
import { Layout } from "./Layout";
import { dataProvider } from "./dataProvider";
import { UserList, UserCreate } from "./users";
import { PostList, PostEdit, PostCreate } from "./Post";
import {authProvider} from "./authProvider";
import {CommentsList, CommentsEdit, CommentsCreate} from "./Comments";
import {AlbumList, AlbumEdit, AlbumCreate} from "./Albums";
import {PhotoList, PhotoEdit, PhotoCreate} from "./photos";
import {TodosList, TodosEdit, TodosCreate} from "./Todo's";

export const App = () => (
  <Admin authProvider= {authProvider} layout={Layout} dataProvider={dataProvider}>
    <Resource name='users' list={UserList} create={UserCreate}/>
    <Resource name='posts' list={PostList} edit={PostEdit} create={PostCreate}/>
    <Resource name='comments' list={CommentsList} create={CommentsCreate} edit={CommentsEdit}/>
    <Resource name='Albums' list={AlbumList} create={AlbumCreate} edit={AlbumEdit}/>
    <Resource name='Photos' list={PhotoList} create={PhotoCreate} edit={PhotoEdit}/>
    <Resource name='Todos' list={TodosList} create={TodosCreate} edit={TodosEdit}/>

    
  </Admin>
);
